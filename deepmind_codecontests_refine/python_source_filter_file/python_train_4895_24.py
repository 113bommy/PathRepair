N = int(input())
M = -1000000000
L = int(input())
for i in range(2,N):
    C = int(input())
    M = max(C - L, M)
    L = min(C, L)
print(M)