n = int(input())
A = list(map(int, input().split()))

def countingSort(A, B, k):
    C = [0] * k
    for j in range(0, n):
        C[A[j]]+=1

    for i in range(1, k):
        C[i] = C[i] + C[i - 1]

    for j in range(0, n)[::-1]:
        B[C[A[j]] - 1] = A[j]
        C[A[j]]-=1
    return B
        
print(' '.join(map(str, countingSort(A, [0] * n, 10000))))
