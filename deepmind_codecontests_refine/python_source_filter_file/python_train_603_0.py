n,m=map(int,input().split())
l=[int(i) for i in input().split()]
for i in l:
    w.append((i+w[-1])%m)
ans=0
d={}
for i in w:
    if i in d:
        d[i]+=1
    else:
        d[i]=1
for i in d:
    ans+=d[i]*(d[i]-1)
print(ans//2)