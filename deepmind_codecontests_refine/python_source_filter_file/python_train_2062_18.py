import sys
sys.setrecursionlimit(10**5)
n, m = map(int, input().split())
adjacent_list = [[] for i in range(n + 1)]
for i in range(m):
    x, y, z = map(int,input().split())
    adjacent_list[x].append(y)
    adjacent_list[y].append(x)
##結局、グラフが何個あるか数える
finished = set()
ans = 0
def dfs(node):
    global finished
    finished.add(node)
    for i in adjacent_list[node]:
        if i not in finished:
            dfs(i)

while len(finished) != n:
    for i in range(1,n+1):
        if i not in finished:
            dfs(i)
            ans += 1
print(ans)


