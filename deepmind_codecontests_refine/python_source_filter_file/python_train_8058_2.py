n,m=map(int,input().split())
a=list(map(int,input().split()))
d={}
l=[1]
for x in a[n-2::-1]:
    l+=[l[-1]]
    if d.get(x,0)==0:
        l[-1]+=1
        d[x]=1
l=l[::-1]
if n==1: l=[1]
ans=[]
for _ in range(m):
    ans+=[str(l[int(input())-1])]
print('\n'.join(ans))