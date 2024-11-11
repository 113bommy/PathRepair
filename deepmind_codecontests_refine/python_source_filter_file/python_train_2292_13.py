#coding: utf-8

def maxHeapify(A, i):
    l = 2 * i
    r = 2 * i  + 1

    if l <= H and A[l] > A[i]:
        largest = l
    else:
        largest = i

    if r <= H and A[r] > A[largest]:
        largest = r

    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        maxHeapify(A, largest)

def buildMaxHeap(A):
    for i in range(H//2, 0, -1):
        maxHeapify(A, i)

H = int(input())
A = [0] + list(map(int,input().split()))
buildMaxHeap(A)
A.pop(0)
print(" ".join([str(num) for num in A]))

