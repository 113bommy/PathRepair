from collections import deque

n=int(input())
a=[list(map(int,input().split())) for i in range(n)]

for i in range(n):
    for j in range(n-1):
        a[i][j]-=1
    a[i].reverse()
print(a)
day=[0]*n
pair=[-1]*n

q=deque(range(n))

while q:
    me=q.popleft()
    if not a[me]:
        continue
    oppo=a[me].pop()
    if pair[oppo]==me:
        now=max(day[me],day[oppo])+1
        day[me]=now
        day[oppo]=now
        q.append(me)
        q.append(oppo)
    else:
        pair[me]=oppo


for i in range(n):
    if a[i]:
        print(-1)
        break
else:
    print(max(day))