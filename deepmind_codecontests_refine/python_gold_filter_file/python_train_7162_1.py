import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

n = int(input())
xy = [[[] for _ in range(10**5+1)] for __ in range(2)]

for _ in range(n):
    x,y = map(int,input().split())
    xy[0][x].append(y)
    xy[1][y].append(x)

ans = 0
used = [[False for _ in range(10**5+1)] for __ in range(2)]

def dfs(i,flag):
    for v in xy[flag][i]:
        if not used[1-flag][v]:
            used[1-flag][v] = True
            dfs(v,1-flag)
            count[1-flag] += 1

for i in range(10**5+1):
    if xy[0][i] and not used[0][i]:
        used[0][i] = True
        count = [1,0]
        dfs(i,0)
        ans += count[0]*count[1]

ans -= n
print(ans)