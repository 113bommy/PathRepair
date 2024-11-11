N = int(input())
A = [int(i) for i in input().split(' ')]

AA = []
for i,a in enumerate(A):
    AA.append(tuple([a,i]))

AA = sorted(AA,reverse=True)
DP =[]
for _ in range(N+1):
    DP.append([0]*(N+1))

for i,a in enumerate(AA):
    for x in range(i+1):
        y = i - x
        if x+ 1 <= N:
            DP[x+1][y] = max(DP[x+1][y], DP[x][y]+a[0]*abs(x-a[1]))
        if y+1 <= N:
            DP[x][y+1] = max(DP[x][y+1], DP[x][y]+a[0]*abs(N- 1 - y - a[1]))

MAX = 0
for x in range(N):
    y = N - x
    MAX = max(DP[x][y],MAX)

print(MAX)