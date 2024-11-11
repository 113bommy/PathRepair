from collections import deque
n,m = map(int,input().split())

net = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())

    net[a].append(b)
    net[b].append(a)

a = [-1] * (n+1)
d = deque()
d.append(1)
while d:
    u = d.popleft()
    for child in net[u]:
        if a[child] != -1:continue
        a[child] = u
        d.append(child)
print("Yes")
print(*a[2:], seq = " ")
