from collections import defaultdict
n=int(input())
ar=list(map(int,input().split()))
m=defaultdict(lambda:-1)
m[0]=-1
st=-1
pre=[]
d=0
ans=0
for i in range(n):
    d+=ar[i]
    pre+=[d]
for i in range(n):
    if m[pre[i]]!=-1 or pre[i]==0:
        st=m[pre[i]]+1        
    m[pre[i]]=i
    ans+=i-st
    #print(ans,m,pre[i],i,st)
print(ans)
