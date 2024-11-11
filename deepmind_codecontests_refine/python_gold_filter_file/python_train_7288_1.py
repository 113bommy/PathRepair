def CountingSort(A, B, k):
    C = [0 for i in range(k+2)]
    
    for j in range(n):
        C[A[j]] += 1
        
    for i in range(k+1):
        C[i] += C[i-1]
        
    for j in range(n-1, -1, -1):
        B[C[A[j]]-1] = A[j]
        C[A[j]] -= 1

if __name__=="__main__":
    n = int(input())
    D = list(map(int, input().split()))
    l = max(D)
    E = D[:]
    CountingSort(D, E, l)
    print(" ".join(map(str, E)))