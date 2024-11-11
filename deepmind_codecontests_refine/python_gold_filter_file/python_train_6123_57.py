import sys
input = sys.stdin.readline

n = int(input())
C = [list(map(int,input().split())) for i in range(n-1)]
mod = 10**9 + 7

for i in range(n-1):
    for j in range(2):
        C[i][j] -= 1

ans = 0
M = [[] for i in range(n)]
for i in range(n-1):
    M[C[i][0]].append(C[i][1])
    M[C[i][1]].append(C[i][0])

D = [[1,1] for i in range(n)]
MN = [len(M[i]) for i in range(n)]
# print("MN", MN)

V = [0] * n
Q = []
for i in range(1, n):
    if MN[i] == 1:
        Q.append(i)
        V[i] = 1

# print(Q)

s = 0
while s < len(Q):
    x = Q[s]
    for y in M[x]:
        if V[y] == 0:
            # print("y",y)
            D[y][0] = (D[y][0] * sum(D[x])) % mod
            D[y][1] = (D[y][1] * D[x][0]) % mod
            MN[y] -= 1
            if (y != 0 and MN[y] == 1) or (y == 0 and MN[y] == 0):
                V[y] = 1
                Q.append(y)
    s += 1

print(sum(D[0]) % mod)
