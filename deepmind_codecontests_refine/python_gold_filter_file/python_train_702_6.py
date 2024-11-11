N = int(input())
A = list(map(int, input().split()))
S = sum(A)
L = [0] * 100001
for i in A:
    L[i] += 1
Q = int(input())
for i in range(Q):
    B, C = map(int, input().split())
    S += (C - B) * L[B]
    L[C] += L[B]
    L[B] = 0
    print(S)