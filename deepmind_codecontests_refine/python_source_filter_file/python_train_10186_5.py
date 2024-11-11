from itertools import permutations
import sys


input = sys.stdin.readline


N, M, R = map(int, input().split())

dest = [x-1 for x in map(int, input().split())]


inf = float('inf')
mat = [[inf]*N for _ in range(N)]
for _ in range(M):
    a, b, c = map(int, input().split())
    mat[a-1][b-1] = mat[b-1][a-1] = c


for i in range(N):
    for j in range(N):
        for k in range(N):
            mat[j][k] = min(mat[j][k], mat[j][i]+mat[i][k])


ans = inf
# for l in permutations(dest):
#    tmp = 0
#    for u, v in zip(l, l[1:]):
#        tmp += mat[u][v]
#    ans = min(ans, tmp)

print(ans)
