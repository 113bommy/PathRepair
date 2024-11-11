from collections import deque
from operator import itemgetter


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

info = [(a[i], b[i]) for i in range(n)]
info = sorted(info, key = itemgetter(1))
for i in range(n):
    a[i], b[i] = info[i]

s = sorted(a)
t = sorted(b)
for i in range(n):
    if s[i] > t[i]:
        print("No")
        exit()

sorted_a = sorted(zip(a, range(len(a))))
graph = [[] for i in range(n)]
for i in range(n):
    u = i
    v = sorted_a[i][1]
    if u != v:
        graph[u].append(v)

used = [False]*n
pos = 0
used[pos] = True
q = deque([pos])
while q:
    pos = q.pop()
    for next_pos in graph[pos]:
        if used[next_pos]:
            continue
        q.append(next_pos)
        used[next_pos] = True

for i in range(n):
    if not used[i]:
        print("Yes")
        exit()

for i in range(n):
    if s[i+1] <= t[i]:
        print("Yes")
        exit()

print("No")