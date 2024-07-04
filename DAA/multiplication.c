#include<stdio.h>

void multiply(int A[][2], int B[][2], int C[][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void add(int A[][2], int B[][2], int C[][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void print(int A[][2])
{
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d  ",A[i][j]);
        }
        printf("\n");

    }
}
void sub(int A[][2], int B[][2], int C[][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}



int main() {
    int a11[2][2], b11[2][2], a22[2][2], b22[2][2], c1[2][2], c2[2][2], m1[2][2];
    int a12[2][2], b12[2][2], a21[2][2], b21[2][2];
   int  m2[2][2], m3[2][2], m4[2][2] ,m5[2][2],m6[2][2], m7[2][2];
   int d11[2][2], d12[2][2],d21[2][2],d22[2][2];

    int a[4][4] = {{0,1,2,3},{2,4,1,3},{3,1,2,5},{1,0,1,2}};
    int b[4][4] = {{6,1,4,3},{1,4,8,2},{0,1,5,5},{1,9,1,0}};

    for(int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a11[i][j] = a[i][j];
            b11[i][j] = b[i][j];
            a12[i][j] = a[i][j+2];
            b12[i][j] = b[i][j+2];
            a21[i][j] = a[i+2][j];
            b21[i][j] = b[i+2][j];
            a22[i][j] = a[i + 2][j + 2];
            b22[i][j] = b[i + 2][j + 2];
        }
    }
    add(a11, a22, c1);
    add(b11, b22, c2);
    multiply(c1, c2, m1);//m1
    
    add(a21, a22,c1);
    multiply(c1,b11,m2);//m2
    
    sub(b21,b22,c2);
    multiply(a11,c2,m3);//m3
    
    sub(b21,b11,c1);
    multiply(a22,c1,m4);//m4
    
    add(a11,a12,c1);
    multiply(c1,b22,m5);//m5
    
    sub(a21,a11,c1);
    add(b11,b12,c2);
    multiply(c1,c2,m6);//m6
    
    sub(a12,a22,c1);
    add(b21,b22,c2);
    multiply(c1,c2,m7);//m7
    
    add(m3,m5,d12);
    add(m2,m4,d21);
    
    
    add(m1,m4,c1);
    sub(c1,m5,c2);
    add(c1,m7,d11);
    
    
    sub(m1,m2,c2);
    add(c2,m3,c1);
    add(c1,m6,d22);
  
  print(d11);
  print(d12);
  print(d21);
  print(d22);

    return 0;
}