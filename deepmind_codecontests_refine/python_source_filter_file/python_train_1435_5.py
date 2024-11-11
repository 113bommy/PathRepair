from collections import deque
n,m = map(int,input().split())
ab=[[] for _ in range(n+1)]
for _ in range(m):
    a,b=map(int,input().split())
    ab[a].append(b) 
    ab[b].append(a)
ans=[0]*(n+1)
ans[1]=1
que=deque()
que.append(1)
while que:
    x=que.popleft()
    for i in ab[x]:
        if ans[i]==0:
            ans[i]=x
            que.append(i)
print("Yse")
for j in range(2,n+1):
  print(ans[j])