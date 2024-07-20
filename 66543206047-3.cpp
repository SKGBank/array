#include <stdio.h> // ใช้สำหรับ printf()
#include <conio.h> // ใช้สำหรับ getch()
#include <stdlib.h>// ใช้สำหรับ malloc()

#define l 1 // ขอบเขตต่ำสุด
#define u 5 // ขอบเขตสูงสุด

#define l1 1 // ขอบเขตต่ำสุด 1
#define u1 3 // ขอบเขตสูงสุด 1

#define l2 1 // ขอบเขตต่ำสุด 2
#define u2 4 // ขอบเขตสูงสุด 2

#define l3 1 // ขอบเขตต่ำสุด 3
#define u3 5 // ขอบเขตสูงสุด 3

int *BA1, *BA2, *BA3, *p ; // พอยน์เตอร์ที่ชี้ไปที่ฐานของแต่ละมิติและพอยน์เตอร์ที่เคลื่อนที่
int i, j, k ; // ตัวดัชนีของอาร์เรย์S


void Create1DArray() {
    int element, c, total_mem ;
    element = (u - l + 1) ; // คำนวณจำนวนสมาชิก
    c = sizeof(*BA1); // คำนวณขนาดของแต่ละบล็อกของอาร์เรย์
    total_mem = element * c ; // คำนวณขนาดทั้งหมด
    BA1 = (int*)malloc(total_mem) ; // จัดสรรหน่วยความจำ
}

void A1(int i, int x) {
    p = BA1 + (i - l); // คำนวณพอยน์เตอร์
    *p = x; // เก็บข้อมูลลงในอาร์เรย์
}

int ReadA1(int i) {
    p = BA1 + (i - l); // คำนวณพอยน์เตอร์
    return (*p); // ส่งค่าที่ตำแหน่งที่คำนวณไว้
}


//---------------------------------------------------------------------
void Create2DArray() {
    int element, c, total_mem;
    element = (u1 - l1 + 1) * (u2 - l2 + 1); // คำนวณจำนวนสมาชิก
    c = sizeof(*BA2); // คำนวณขนาดของแต่ละบล็อกของอาร์เรย์
    total_mem = element * c; // คำนวณขนาดทั้งหมด
    BA2 = (int*)malloc(total_mem); // จัดสรรหน่วยความจำ
}

void A2(int i, int j, int x) {
    p = BA2 + ((i - l1) * (u2 - l2 + 1) + (j - l2)); // คำนวณพอยน์เตอร์
    *p = x; // เก็บข้อมูลลงในอาร์เรย์
}

int ReadA2(int i, int j) {
    p = BA2 + ((i - l1) * (u2 - l2 + 1) + (j - l2)); // คำนวณพอยน์เตอร์
    return (*p); // ส่งค่าที่ตำแหน่งที่คำนวณไว้
}

//---------------------------------------------------------------------
void Create3DArray() {
    int element, c, total_mem;
    element = (u1 - l1 + 1) * (u2 - l2 + 1) * (u3 - l3 + 1); // คำนวณจำนวนสมาชิก
    c = sizeof(*BA3); // คำนวณขนาดของแต่ละบล็อกของอาร์เรย์
    total_mem = element * c; // คำนวณขนาดทั้งหมด
    BA3 = (int*)malloc(total_mem); // จัดสรรหน่วยความจำ
}

void A3(int i, int j, int k, int x) {
    p = BA3 + ((i - l1) * (u2 - l2 + 1) * (u3 - l3 + 1) + (j - l2) * (u3 - l3 + 1) + (k - l3)); // คำนวณพอยน์เตอร์
    *p = x; // เก็บข้อมูลลงในอาร์เรย์
}

int ReadA3(int i, int j, int k) {
    p = BA3 + ((i - l1) * (u2 - l2 + 1) * (u3 - l3 + 1) + (j - l2) * (u3 - l3 + 1) + (k - l3)); // คำนวณพอยน์เตอร์
    return (*p); // ส่งค่าที่ตำแหน่งที่คำนวณไว้
}

//---------------------------------------------------------------------
int main() {
    printf("1-3 DIMENSION ARRAY FUNCTION...\n");
    printf("=================================\n");

    // สร้างอาร์เรย์
    Create1DArray();
    Create2DArray();
    Create3DArray();

    // ใช้งานอาร์เรย์ 1 มิติ
    i = 2;
    A1(i, 9);
    printf("\nA1(%d) = %d ", i, ReadA1(i));

    // ใช้งานอาร์เรย์ 2 มิติ
    i = 2; j = 3;
    A2(i, j, 99);
    printf("\nA2(%d,%d) = %d ", i, j, ReadA2(i, j));

    // ใช้งานอาร์เรย์ 3 มิติ
    i = 3; j = 4; k = 5;
    A3(i, j, k, 999);
    printf("\nA3(%d,%d,%d) = %d ", i, j, k, ReadA3(i, j, k));

    getch(); // รอการกดคีย์บอร์ด
    free(BA1); // คืนหน่วยความจำที่จองไว้สำหรับแต่ละอาร์เรย์
    free(BA2);
    free(BA3);
    return 0;
}

