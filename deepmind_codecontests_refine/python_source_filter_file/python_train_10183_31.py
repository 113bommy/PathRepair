import heapq
n,k=map(int,input().split())
td=[[0]*2 for _ in range(n)]
for i in range(n):
    t,d=map(int,input().split())
    td[i][0],td[i][1]=d,t
td.sort(reverse=True)
di=set()
sa=[]
heapq.heapify(sa)
ans=0
for d,t in td[:k]:
    if t in di:
        heapq.heappush(sa, d)
    else:
        di.add(t)
    ans+=d

s=[0]*(k+1)
cnt=len(di)
s[cnt]=ans
for d,t in td[k:]:
    if t in di:
        continue
    else:
        if sa:
            x=heapq.heappop(sa)
            ans+=d-x
            di.add(t)
            cnt+=1
            s[cnt]=ans

for i in range(k+1):
    s[i]+=i*i

print(max(s))