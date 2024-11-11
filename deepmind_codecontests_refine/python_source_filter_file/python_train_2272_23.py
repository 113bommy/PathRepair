from collections import defaultdict
N,C = map(int,input().split())
D = [list(map(int,input().split())) for _ in range(C)]
c = [list(map(int,input().split())) for _ in range(N)]

strange = [defaultdict(lambda:0) for _ in range(3)]
for i in range(N):
    for j in range(N):
        for color in range(C):
            strange[(i+j)%3][color] += D[c[i][j]-1][color]

ans = 1000*N**2
ref = 0
for c1 in range(C):
    for c2 in range(C):
        for c3 in range(C):
            if c1 != c2 and c2 != c3 and c3 != c1:
                ans = min(ans,strange[0][c1]+strange[1][c2]+strange[2][c3])
print(ans)