#include <stdio.h>
#include <string.h>

// ฟังก์ชัน reverse: กลับข้อความ str1 และเก็บผลลัพธ์ไว้ใน str2
void reverse(char str1[], char str2[]) {
    int len = strlen(str1); // ความยาวของ str1
    for (int i = 0; i < len; i++) {
        str2[i] = str1[len - i - 1]; // ก๊อปปี้ตัวอักษรจากท้ายมาหัว
    }
    str2[len] = '\0'; // ใส่ null-terminator ที่ท้าย str2
}

int main() {
    char text[50]; // เก็บข้อความต้นฉบับ
    char out[50];  // เก็บข้อความที่กลับหน้าไปหลัง

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin); // รับข้อความจากผู้ใช้ (ใช้ fgets เพื่อป้องกัน buffer overflow)

    // ลบ newline character (ถ้ามี) จากการใช้ fgets
    text[strcspn(text, "\n")] = '\0';

    reverse(text, out); // เรียกใช้ฟังก์ชัน reverse

    // แสดงผลลัพธ์
    printf("Output: %s\n", out);

    return 0;
}
