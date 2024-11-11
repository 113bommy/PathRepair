import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

N,M,P = map(int,input().split())
ABC = [[int(x) for x in input().split()] for _ in range(M)]

INF = 10 ** 18
dist = [INF] * (N+1)
dist[1] = 0

loop = False
for i in range(2*N+100):
    for a,b,c in ABC:
        x = dist[a] + P - c
        if dist[b] > x:
            dist[b] = x
            if b == N and i > N:
                loop = True

if loop:
    answer = -1
else:
    answer = -dist[N]
    if answer < 0:
        answer = 0

print(answer)
