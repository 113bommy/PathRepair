n = int(input())
ab = [list(map(int,input().split())) for _ in range(n-1)]
c = list(map(int,input().split()))

c.sort(reverse = True)
edges = [[] for _ in range(n)]
ans = [-1]*n
ans[0] = c[0]
count = 1

for a,b in ab:
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)

q = [0]

while q:
    l = q.pop(-1)
    for l1 in edges[l]:
        if ans[l1] == -1:
            q.append(l1)
            ans[l1] = c[count]
            count += 1

print(sum(c[1:]))
for i in ans:
    print(i, end = ' ')
