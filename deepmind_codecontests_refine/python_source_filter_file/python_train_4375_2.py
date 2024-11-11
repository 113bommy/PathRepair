import sys
readline = sys.stdin.readline
def partition(A, p, r):
    x = A[r][1]
    i = p - 1
    for j in range(p, r):
        if A[j][1] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[r] = A[r], A[i + 1]
    return i + 1
def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q - 1)
        quicksort(A, q + 1, r)
def isStable(A):
    for i in range(0, len(A) - 1):
        if A[i][1] == A[i + 1][1]:
            if A[i][2] > A[i + 1][2]:
                return False
    return True
n = int(input())
f = lambda a: (a[0], int(a[1]))
A = [f(readline().split()) + (i) for i in range(n)]
quicksort(A, 0, n - 1)
print("Stable" if isStable(A) else "Not stable")
print("\n".join(f"{a} {b}" for a, b, c in A))

