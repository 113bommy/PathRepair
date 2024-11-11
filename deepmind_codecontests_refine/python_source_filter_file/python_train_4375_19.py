#coding:utf-8
from copy import deepcopy
n = int(input())
A = []
for i in range(n):
    ch, num = input().split()
    A.append([ch, int(num)])

B = deepcopy(A)



def Merge(A, left, mid, right):
    L = A[left:mid]
    R = A[mid:right]
    L.append(["S",20000000])
    R.append(["S",20000000])
    i,j = 0,0
    for k in range(left,right):
        if L[i][1] <= R[j][1]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def MergeSort(A, left, right):
    if left+1 < right:
        mid = (left + right)//2
        MergeSort(A, left, mid)
        MergeSort(A, mid, right)
        Merge(A, left, mid, right)

    

def partition(A, p, r):
    x = A[r-1][1]
    i = p-1
    for j in range(p, r):
        if A[j][1] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    return i


def quickSort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quickSort(A, p, q)
        quickSort(A, q+1, r)




        
quickSort(A, 0, n)
MergeSort(B, 0, n)

if A == B:
    print("Stable")
else:
    print("Not stable")
    
for a in A:
    a = " ".join([a[0],str(a[1])])
    print(a)
