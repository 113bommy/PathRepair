def depth_search(u, t):
    t += 1
    s.append(u)
    d[u] = t
    for v in range(N):
        if adjacency_list[u][v] == 0:
            continue 
        if d[v] == 0 and v not in s:
            t = depth_search(v, t)
    t += 1
    s.pop()
    f[u] = t
    return t

N = int(input())
adjacency_list = [[0 for j in range(N)] for i in range(N)]
for _ in range(N):
    u, k, *v = input().split()
    for i in v:
        adjacency_list[int(u)-1][int(i)-1] = 1

s = []
d = [0 for _ in range(N)]
f = [0 for _ in range(N)]

t = 0
for u in range(N):
    if d[u] == 0:
        t = depth_search(u, t)

for i in range(N):
    print("{} {} {}".format(i+1, d[i], f[i]))
