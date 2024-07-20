#include <stdio.h> // ������Ѻ printf()
#include <conio.h> // ������Ѻ getch()
#include <stdlib.h>// ������Ѻ malloc()

#define l 1 // �ͺࢵ����ش
#define u 5 // �ͺࢵ�٧�ش

#define l1 1 // �ͺࢵ����ش 1
#define u1 3 // �ͺࢵ�٧�ش 1

#define l2 1 // �ͺࢵ����ش 2
#define u2 4 // �ͺࢵ�٧�ش 2

#define l3 1 // �ͺࢵ����ش 3
#define u3 5 // �ͺࢵ�٧�ش 3

int *BA1, *BA2, *BA3, *p ; // ��¹���������价��ҹ�ͧ�����Ե���о�¹�����������͹���
int i, j, k ; // ��ǴѪ�բͧ��������S


void Create1DArray() {
    int element, c, total_mem ;
    element = (u - l + 1) ; // �ӹǳ�ӹǹ��Ҫԡ
    c = sizeof(*BA1); // �ӹǳ��Ҵ�ͧ���к��͡�ͧ��������
    total_mem = element * c ; // �ӹǳ��Ҵ������
    BA1 = (int*)malloc(total_mem) ; // �Ѵ���˹��¤�����
}

void A1(int i, int x) {
    p = BA1 + (i - l); // �ӹǳ��¹�����
    *p = x; // �红�����ŧ���������
}

int ReadA1(int i) {
    p = BA1 + (i - l); // �ӹǳ��¹�����
    return (*p); // �觤�ҷ����˹觷��ӹǳ���
}


//---------------------------------------------------------------------
void Create2DArray() {
    int element, c, total_mem;
    element = (u1 - l1 + 1) * (u2 - l2 + 1); // �ӹǳ�ӹǹ��Ҫԡ
    c = sizeof(*BA2); // �ӹǳ��Ҵ�ͧ���к��͡�ͧ��������
    total_mem = element * c; // �ӹǳ��Ҵ������
    BA2 = (int*)malloc(total_mem); // �Ѵ���˹��¤�����
}

void A2(int i, int j, int x) {
    p = BA2 + ((i - l1) * (u2 - l2 + 1) + (j - l2)); // �ӹǳ��¹�����
    *p = x; // �红�����ŧ���������
}

int ReadA2(int i, int j) {
    p = BA2 + ((i - l1) * (u2 - l2 + 1) + (j - l2)); // �ӹǳ��¹�����
    return (*p); // �觤�ҷ����˹觷��ӹǳ���
}

//---------------------------------------------------------------------
void Create3DArray() {
    int element, c, total_mem;
    element = (u1 - l1 + 1) * (u2 - l2 + 1) * (u3 - l3 + 1); // �ӹǳ�ӹǹ��Ҫԡ
    c = sizeof(*BA3); // �ӹǳ��Ҵ�ͧ���к��͡�ͧ��������
    total_mem = element * c; // �ӹǳ��Ҵ������
    BA3 = (int*)malloc(total_mem); // �Ѵ���˹��¤�����
}

void A3(int i, int j, int k, int x) {
    p = BA3 + ((i - l1) * (u2 - l2 + 1) * (u3 - l3 + 1) + (j - l2) * (u3 - l3 + 1) + (k - l3)); // �ӹǳ��¹�����
    *p = x; // �红�����ŧ���������
}

int ReadA3(int i, int j, int k) {
    p = BA3 + ((i - l1) * (u2 - l2 + 1) * (u3 - l3 + 1) + (j - l2) * (u3 - l3 + 1) + (k - l3)); // �ӹǳ��¹�����
    return (*p); // �觤�ҷ����˹觷��ӹǳ���
}

//---------------------------------------------------------------------
int main() {
    printf("1-3 DIMENSION ARRAY FUNCTION...\n");
    printf("=================================\n");

    // ���ҧ��������
    Create1DArray();
    Create2DArray();
    Create3DArray();

    // ��ҹ�������� 1 �Ե�
    i = 2;
    A1(i, 9);
    printf("\nA1(%d) = %d ", i, ReadA1(i));

    // ��ҹ�������� 2 �Ե�
    i = 2; j = 3;
    A2(i, j, 99);
    printf("\nA2(%d,%d) = %d ", i, j, ReadA2(i, j));

    // ��ҹ�������� 3 �Ե�
    i = 3; j = 4; k = 5;
    A3(i, j, k, 999);
    printf("\nA3(%d,%d,%d) = %d ", i, j, k, ReadA3(i, j, k));

    getch(); // �͡�á��������
    free(BA1); // �׹˹��¤����ӷ��ͧ�������Ѻ������������
    free(BA2);
    free(BA3);
    return 0;
}

