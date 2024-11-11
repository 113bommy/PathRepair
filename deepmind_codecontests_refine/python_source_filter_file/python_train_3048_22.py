# 改行でバグる時
import sys
input = lambda: sys.stdin.readline().rstrip()

t=int(input())
g= [list(map(int, input().split())) for i in range(t)]
ans=[0]*t
print(g)
for i in range(t):
    a=g[i][0]
    b=g[i][1]
    for j in range(30):
        if (a >> j) & 1 or (b >> j) & 1:
            if not( (a >> j) & 1 and (b >> j) & 1):
                ans[i]+=pow(2,j)

for i in range(t):
    print(ans[i])