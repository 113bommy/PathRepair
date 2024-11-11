from sys import stdin
input = stdin.readline

n, m = map(int, input().split())
arr = sorted(list(map(int, input().split())))
que, vis = [], {}
for i in arr:
    que.append((i, 1))
    vis[i] = 1

def bfs():
    tot_sum, res = 0, []
    p1, p2 = 0, len(que)-1
    while p1 < p2:
        x, y = que[p1]
        p1 += 1
        if x+1 not in vis:
            vis[x+1] = 1
            que.append((x+1, y+1))
            p2 += 1
            tot_sum += y
            res.append(x+1)
        if len(res) == m:
            break
        if x-1 not in vis:
            vis[x-1] = 1
            que.append((x-1, y+1))
            p2 += 1
            tot_sum += y
            res.append(x-1)
        if len(res) == m:
            break
    return tot_sum, res

tot_sum, res = bfs()
print(tot_sum)
print(*res)
