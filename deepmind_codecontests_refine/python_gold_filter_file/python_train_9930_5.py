import sys
input = sys.stdin.readline

'''

'''

n, m = map(int, input().split())
g = [[] for _ in range(n)]

for _ in range(m):
    x, y = map(int, input().split())
    g[x-1].append(y-1)
    g[y-1].append(x-1)

s = set()
for l in g:
    s.add(len(l))

if s == {2}:
    print("ring topology")
elif s == {1,2}:
    print("bus topology")
elif s == {1, m}:
    print("star topology")
else:
    print("unknown topology")