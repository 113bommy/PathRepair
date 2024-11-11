def Z_algorithm(s):
    n = len(s)
    A = [n] + [0] * (n-1)
    i, j = 1, 0
    while i < n:
        while i + j < n and s[j] == s[i+j]:
            j += 1
        A[i] = j
        if j == 0:
            i += 1
            continue
        k = 1
        while i + k < n and k + A[k] < j:
            A[i+k] = A[k]
            k += 1
        i += k
        j -= k
    return A

N = int(input())
A = [int(a) for a in input().split()]
B = [int(a) for a in input().split()]
AA = [A[i] ^ A[i-1] for i in range(N)]
BB = [B[i] ^ B[i-1] for i in range(N)]

T = Z_algorithm(AA + [-1] + BB + BB)
for i in range(N, 0, -1):
    if T[N+i] >= N:
        print(N-i, A[-i%N] ^ B[0])