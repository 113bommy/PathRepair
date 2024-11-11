n, s, t = map(int, input().split())
p = list(map(int, input().split()))
path = dict()
vis = [0]*n
for i in range(n):
    path[i] = p[i] - 1
i = s-1
while path[i] != (t-1) and vis[i] != 1:
    vis[i] = 1
    i = path[i]
if s==t:
    print(0)
elif path[i] == t-1:
    print(vis.count(1))
else:
    print('-1')

