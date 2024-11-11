H = int(input())
def maxHeapify(A, i):
    l = 2 * i + 1
    r = 2 * i + 2
    if l < H and A[l] > A[i]:
        largest = l
    else:
        largest = i
    if r < H and A[r] > A[largest]:
        largest = r
    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        maxHeapify(A, largest)

def buildMaxHeap(A):
    for i in range(H//2 + 1, -1, -1):
        maxHeapify(A, i)

A = [int(i) for i in input().split()]
buildMaxHeap(A)
print(' '.join(map(str,A)))