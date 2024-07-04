#include <stdio.h>

void multiply(int A[][2], int B[][2], int C[][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void add(int A[][2], int B[][2], int C[][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void print(int A[][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }
}
void sub(int A[][2], int B[][2], int C[][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

int main()
{
    int a11[2][2], b11[2][2], a22[2][2], b22[2][2], c1[2][2], c2[2][2], m1[2][2];
    int a12[2][2], b12[2][2], a21[2][2], b21[2][2];
    int m2[2][2], m3[2][2], m4[2][2], m5[2][2], m6[2][2], m7[2][2];
    int d11[2][2], d12[2][2], d21[2][2], d22[2][2];

    int a[4][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {2, 2, 2, 2}};

    int b[4][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {2, 2, 2, 2}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a11[i][j] = a[i][j];
            b11[i][j] = b[i][j];
            a12[i][j] = a[i][j + 2];
            b12[i][j] = b[i][j + 2];
            a21[i][j] = a[i + 2][j];
            b21[i][j] = b[i + 2][j];
            a22[i][j] = a[i + 2][j + 2];
            b22[i][j] = b[i + 2][j + 2];
        }
    }
    add(a11, a22, c1);
    add(b11, b22, c2);
    multiply(c1, c2, m1); // m1

    add(a21, a22, c1);
    multiply(c1, b11, m2); // m2

    sub(b21, b22, c2);
    multiply(a11, c2, m3); // m3

    sub(b21, b11, c1);
    multiply(a22, c1, m4); // m4

    add(a11, a12, c1);
    multiply(c1, b22, m5); // m5

    sub(a21, a11, c1);
    add(b11, b12, c2);
    multiply(c1, c2, m6); // m6

    sub(a12, a22, c1);
    add(b21, b22, c2);
    multiply(c1, c2, m7); // m7

    add(m3, m5, d12);
    add(m2, m4, d21);

    add(m1, m4, c1);
    add(c1, m7, c2);
    sub(c2, m5, d11);

    sub(m1, m2, c2);
    add(c2, m3, c1);
    add(c1, m6, d22);
    printf("name: Shiv Patel\n");
    printf("Roll No: 22BCP317\n");
    print(d11);
    print(d12);
    print(d21);
    print(d22);

    return 0;
}

// #include<stdio.h>

// void multiply(int A[][n/2], int B[][n/2], int C[][n/2]) {
//     for (int i = 0; i < n/2; i++) {
//         for (int j = 0; j < n/2; j++) {
//             C[i][j] = 0;
//             for (int k = 0; k < n/2; k++) {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }
// }

// void add(int A[][n/2], int B[][n/2], int C[][n/2]) {
//     for (int i = 0; i < 2; i++) {
//         for (int j = 0; j < 2; j++) {
//             C[i][j] = A[i][j] + B[i][j];
//         }
//     }
// }
// void print(int A[][2])
// {
//     for (int i = 0; i < 2; i++) {
//         for (int j = 0; j < 2; j++) {
//             printf("%d  ",A[i][j]);
//         }
//         printf("\n");

//     }
// }
// void sub(int A[][2], int B[][2], int C[][2]) {
//     for (int i = 0; i < 2; i++) {
//         for (int j = 0; j < 2; j++) {
//             C[i][j] = A[i][j] - B[i][j];
//         }
//     }
// }

// int main() {
//     int a11[2][2], b11[2][2], a22[2][2], b22[2][2], c1[2][2], c2[2][2], m1[2][2];
//     int a12[2][2], b12[2][2], a21[2][2], b21[2][2];
//    int  m2[2][2], m3[2][2], m4[2][2] ,m5[2][2],m6[2][2], m7[2][2];
//    int d11[2][2], d12[2][2],d21[2][2],d22[2][2];

//     int a[4][4] = {{1,1,1,1},{2,2,2,2},{3,3,3,3},{1,1,1,1}};

//     int b[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};

//     for(int i = 0; i < n/2; i++) {
//         for (int j = 0; j < n/2; j++) {
//             a11[i][j] = a[i][j];
//             b11[i][j] = b[i][j];
//             a12[i][j] = a[i][j + n/2];
//             b12[i][j] = b[i][j + n/2];
//             a21[i][j] = a[i + n/2][j];
//             b21[i][j] = b[i + n/2][j];
//             a22[i][j] = a[i + n/2][j + n/2];
//             b22[i][j] = b[i + n/2][j + n/2];
//         }
//     }
//     add(a11, a22, c1);
//     add(b11, b22, c2);
//     multiply(c1, c2, m1);//m1

//     add(a21, a22,c1);
//     multiply(c1,b11,m2);//m2

//     sub(b21,b22,c2);
//     multiply(a11,c2,m3);//m3

//     sub(b21,b11,c1);
//     multiply(a22,c1,m4);//m4

//     add(a11,a12,c1);
//     multiply(c1,b22,m5);//m5

//     sub(a21,a11,c1);
//     add(b11,b12,c2);
//     multiply(c1,c2,m6);//m6

//     sub(a12,a22,c1);
//     add(b21,b22,c2);
//     multiply(c1,c2,m7);//m7

//     add(m3,m5,d12);
//     add(m2,m4,d21);

//     add(m1,m4,c1);
//     add(c1,m7,c2);
//     sub(c2,m5,d11);

//     sub(m1,m2,c2);
//     add(c2,m3,c1);
//     add(c1,m6,d22);

//   print(d11);
//    print(d12);
//   print(d21);
//   print(d22);

//     return 0;
// }

// vector<vector<int>> strassenMul(const vector<vector<int>> &arr1,const vector<vector<int>> &arr2)
// {
//     int N = arr1.size();
//     if(N == 1)
//     {
//         return {{arr1[0][0] * arr2[0][0]}};
//     }
//     int newSize = N/2;
//     vector<vector<int>> A11(newSize, vector<int>(newSize, 0));
//     vector<vector<int>> A12(newSize, vector<int>(newSize, 0));
//     vector<vector<int>> A21(newSize, vector<int>(newSize, 0));
//     vector<vector<int>> A22(newSize, vector<int>(newSize, 0));

//     vector<vector<int>> B11(newSize, vector<int>(newSize, 0));
//     vector<vector<int>> B12(newSize, vector<int>(newSize, 0));
//     vector<vector<int>> B21(newSize, vector<int>(newSize, 0));
//     vector<vector<int>> B22(newSize, vector<int>(newSize, 0));

//     for(int i=0; i<newSize; i++)
//     {
//         for(int j=0; j<newSize; j++)
//         {
//             A11[i][j] = arr1[i][j];
//             A12[i][j] = arr1[i][newSize+j];
//             A21[i][j] = arr1[i+newSize][j];
//             A22[i][j] = arr1[i+newSize][j+newSize];

//             B11[i][j] = arr2[i][j];
//             B12[i][j] = arr2[i][newSize+j];
//             B21[i][j] = arr2[i+newSize][j];
//             B22[i][j] = arr2[i+newSize][j+newSize];
//         }
//     }

//    vector<vector<int>> P1 = strassenMul(addition(A11, A22), addition(B11, B22));
//     vector<vector<int>> P2 = strassenMul(addition(A21, A22), B11);
//     vector<vector<int>> P3 = strassenMul(A11, subtraction(B12, B22));
//     vector<vector<int>> P4 = strassenMul(A22, subtraction(B21, B11));
//     vector<vector<int>> P5 = strassenMul(addition(A11, A12), B22);
//     vector<vector<int>> P6 = strassenMul(subtraction(A21, A11), addition(B11, B12));
//     vector<vector<int>> P7 = strassenMul(subtraction(A12, A22), addition(B21, B22));

//     vector<vector<int>> C11 = addition(subtraction(addition(P1, P4), P5), P7);
//     vector<vector<int>> C12 = addition(P3, P5);
//     vector<vector<int>> C21 = addition(P2, P4);
//     vector<vector<int>> C22 = addition(subtraction(addition(P1, P3), P2), P6);

//     vector<vector<int>> result(N, vector<int>(N));
//     for (int i = 0; i < newSize; ++i) {
//         for (int j = 0; j < newSize; ++j) {
//             result[i][j] = C11[i][j];
//             result[i][j + newSize] = C12[i][j];
//             result[i + newSize][j] = C21[i][j];
//             result[i + newSize][j + newSize] = C22[i][j];

//         }
//     }
//     return result;

// }