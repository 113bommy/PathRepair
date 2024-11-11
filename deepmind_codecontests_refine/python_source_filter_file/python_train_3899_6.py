n,v = map(int,input().split())
lis=[0]*(4000)
for i in range(n):
    a,b = map(int,input().split())
    lis[a]+=b
prev=0
ans=0
for i in range(1,3001):
    cap=v
    cap=v-min(prev,v)
    ans+=min(prev,v)
    zz=min(lis[i],cap)
    ans+=zz
    prev=lis[i]-zz
print(ans)    

