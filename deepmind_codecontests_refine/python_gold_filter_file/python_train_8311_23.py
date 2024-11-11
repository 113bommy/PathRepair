import sys
sys.setrecursionlimit(1000000)

n = int(input())
tree = [[] for i in range(n)]
for i in range(n - 1):
    j = int(input())
    j -= 1
    i += 1
    tree[i].append(j)
    tree[j].append(i)

def dfs(pos):
    if pos != 0 and len(tree[pos]) == 1:
        return 1
    li = []
    for next_pos in tree[pos]:
        if visited[next_pos]:
            continue
        visited[next_pos] = True
        li.append(dfs(next_pos))
    li = sorted(li)
    res = 0
    for i in range(len(li)):
        if li[i] > res:
            res = li[i]
        elif li[i] <= res:
            res += 1
    return res + 1

visited = [False] * n
visited[0] = True
print(dfs(0) - 1)
