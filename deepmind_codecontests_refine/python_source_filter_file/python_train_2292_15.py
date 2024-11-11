#!/usr/bin/python3
def left(i):
    return i * 2

def right(i):
    return i * 2 + 1

def maxHeapify(A, i):
    H = len(A) - 1
    l = left(i)
    r = right(i)

    child = {}
    child[i] = A[i] 
    if l <= H:
        child[l] = A[l]
    if r <= H:
        child[r] = A[r]
    largest = max(child.items(), key=lambda x:x[1])[0]

    
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        maxHeapify(A, largest)

def buildMaxHeap(A):
    H = len(A) - 1
    for i in range(H//2, 0, -1):
        maxHeapify(A, i)
    print(' '.join(list(map(str, A[1:]))))

# main
H = int(input())
A = list(map(int, input().split()))
B = [0]
B.extend(A)
buildMaxHeap(B)