n,m=map(int,input().split())
s=[]
for i in range(m):
    a,b=map(int,input().split())
    s.append([a,b-1])
s.sort(key=lambda x:x[1])
ans=0
t=None
for i,j in s:
    if(t is None or t<i):
        t=i
        ans+=1

print(ans)