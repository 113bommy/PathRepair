#coding:utf-8
H = int(input())
A = list(map(int,input().split()))

def maxHeapify(A,i):
    l = 2 * i
    r = 2 * i + 1
    if l <= H and A[l-1] > A[i-1]:
        largest = l
    else:
        largest = i
    if r <= H and A[r-1] > A[largest-1]:
        largest = r
    if largest != i:
        A[i-1], A[largest-1] = A[largest-1], A[i-1]
        maxHeapify(A,largest)

def buildMaxHeap(A):
    for i in range(H // 2, 0, -1):
        maxHeapify(A,i)

buildMaxHeap(A)
A = " ".join([str(num) for num in A])
print(A)

