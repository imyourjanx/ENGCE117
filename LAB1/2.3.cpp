#include <stdio.h>
#include <string.h>

// ฟังก์ชัน explode() สำหรับแยกข้อความ
void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i = 0, j = 0, k = 0;
    *count = 0; // ตั้งค่าตัวนับคำเริ่มต้นเป็น 0

    // ลบตัวแบ่งที่อยู่ข้างหน้าข้อความ
    while (str1[i] == splitter) i++;

    // คำนวณความยาวของข้อความ และลบตัวแบ่งที่อยู่ท้ายข้อความ
    int len = strlen(str1);
    while (len > 0 && str1[len - 1] == splitter) len--;

    // วนลูปแยกข้อความตามตัวแบ่ง
    for (; i < len; i++) {
        if (str1[i] == splitter) { 
            if (k > 0) { // ถ้าพบตัวแบ่งและคำก่อนหน้ามีความยาว
                str2[*count][k] = '\0'; // ปิดข้อความด้วย null-terminator
                (*count)++; // เพิ่มตัวนับคำ
                k = 0; // รีเซ็ตตำแหน่งตัวอักษรในคำถัดไป
            }
        } else {
            str2[*count][k++] = str1[i]; // เก็บตัวอักษรปัจจุบันลงในคำ
        }
    }
    if (k > 0) { // กรณีที่คำสุดท้ายไม่มีตัวแบ่งต่อท้าย
        str2[*count][k] = '\0';
        (*count)++;
    }
}

int main() {
    char input[100], splitter, out[20][10];
    int num;

    // รับข้อความที่ต้องการแยกจากผู้ใช้
    printf("Enter the string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // ลบ newline ที่เกิดจากการกด Enter

    // รับตัวอักษรที่ใช้เป็นตัวแบ่ง
    printf("Enter the splitter character: ");
    scanf(" %c", &splitter);

    // เรียกใช้ฟังก์ชัน explode()
    explode(input, splitter, out, &num);

    // แสดงผลลัพธ์
    printf("\nOutput:\n");
    for (int i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]); // แสดงคำที่แยกได้
    }
    printf("count = %d\n", num); // แสดงจำนวนคำทั้งหมด

    return 0;
}
