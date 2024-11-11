import sys
input = sys.stdin.readline
N = int(input())
tree = [[] for i in range(N+1)]

for i in range(N-1):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

dist_fennec = [100001] * (N+1)
dist_snuke = [100001] * (N+1)
q = [1]
dist_fennec[1] = 0
while q:
    now = q.pop()
    for next in tree[now]:
        if dist_fennec[next] == 100001:
            dist_fennec[next] = dist_fennec[now] + 1
            q.append(next)

q = [N]
dist_snuke[N] = 0
while q:
    now = q.pop()
    for next in tree[now]:
        if dist_snuke[next] == 100001:
            dist_snuke[next] = dist_snuke[now] + 1
            q.append(next)

fennec, snuke = 0, 0
for i in range(1, N+1):
    if dist_snuke[i] <= dist_fennec[i]:
        fennec += 1
    else:
        snuke += 1

if fennec > snuke:
    print("Fennec")
else:
    print("Snuke")
