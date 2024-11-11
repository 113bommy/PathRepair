#coding:utf-8
from copy import deepcopy

n = int(input())
A = list(input().split())
B = deepcopy(A)


def BubbleSort(A,N):
    for i in range(N):
        for j in range(N-1,i,-1):
            if A[j][1] < A[j-1][1]:
                A[j], A[j-1] = A[j-1], A[j]


def SelectionSort(A,N):
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j][1] < A[minj][1]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        
                
BubbleSort(A,n)
SelectionSort(B,n)
A = " ".join([data for data in A])
B = " ".join([data for data in B])

print(A)
print("Stable")

print(B)
if A == B:
    print("Stable")
else:
    print("Not stable")

