from collections import deque

n=int(input())

g=[[] for _ in range(n+1)]

for _ in range(n-1):
    a,b=list(map(int,input().split()))
    g[a].append(b)
    g[b].append(b)

c=sorted(list(map(int,input().split())))
print(sum(c[:-1]))

q=deque([1])
visit=[0]*(n+1)
ans=['']*(n+1)

while len(q)>0:
    u=q.popleft()

    visit[u]=1

    ans[u]=str(c.pop())

    for v in g[u]:
        if visit[v]:
            continue

        q.append(v)

print(' '.join(ans[1:]))