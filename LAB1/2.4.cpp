#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ฟังก์ชันตรวจสอบว่าตัวอักษรปัจจุบันเป็นตัวแบ่งหรือไม่
int is_splitter(char c, char splitters[]) {
    for (int i = 0; splitters[i] != '\0'; i++) {
        if (c == splitters[i]) {
            return 1; // ถ้าตัวอักษรเป็นตัวแบ่ง
        }
    }
    return 0; // ถ้าตัวอักษรไม่ใช่ตัวแบ่ง
}

// ฟังก์ชัน explode() สำหรับแยกข้อความ
void explode(char str1[], char splitters[], char str2[][10], int *count) {
    int i = 0, k = 0; // i ใช้เดินในข้อความ, k ใช้ใส่ตัวอักษรในคำ
    *count = 0; // ตั้งค่าตัวนับเริ่มต้นเป็น 0

    for (int j = 0; str1[j] != '\0'; j++) { // วนลูปจนกว่าจะจบข้อความ
        if (is_splitter(str1[j], splitters)) { // ถ้าพบตัวแบ่ง
            if (k > 0) { // ถ้าคำที่กำลังสร้างมีความยาว
                str2[*count][k] = '\0'; // ปิดท้ายคำด้วย null terminator
                (*count)++; // เพิ่มจำนวนคำ
                k = 0; // รีเซ็ตตำแหน่งสำหรับคำถัดไป
            }
        } else if (!isspace(str1[j])) { // ถ้าไม่ใช่ช่องว่าง
            str2[*count][k++] = str1[j]; // เพิ่มตัวอักษรลงในคำปัจจุบัน
        }
    }
    if (k > 0) { // กรณีที่คำสุดท้ายไม่มีตัวแบ่งต่อท้าย
        str2[*count][k] = '\0';
        (*count)++;
    }
}

int main() {
    char str1[100], splitters[10], out[20][10];
    int count;

    // รับข้อความที่ต้องการแยก
    printf("Enter the string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // ลบ newline ที่เกิดจากการกด Enter

    // รับตัวอักขระตัวแบ่ง
    printf("Enter the splitter characters: ");
    fgets(splitters, sizeof(splitters), stdin);
    splitters[strcspn(splitters, "\n")] = '\0'; // ลบ newline ที่เกิดจากการกด Enter

    // เรียกใช้ฟังก์ชัน explode()
    explode(str1, splitters, out, &count);

    // แสดงผลลัพธ์
    printf("\nOutput:\n");
    for (int i = 0; i < count; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    printf("count = %d\n", count);

    return 0;
}
