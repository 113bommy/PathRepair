n=int(input())
ans=[]
l=list(map(int,input().split()))
if min(l)>=0:
    m=1
if max(l)<0:
    m=-2
if max(l)>0 and min(l)<0:
    if max(l)>=-min(l):
        m=max(l)
    else:
        m=min(l)
    mi=l.index(m)
    for i in range(n):
        if m>0:
            if l[i]<0:
                ans.append([mi+1,i+1])
        else:
            if l[i]>0:
                ans.append([mi+1,i+1])
if m>0:
    for i in range(n-1):
        ans.append([i+1,i+2])
else:
    for i in range(n,1,-1):
        ans.append([i,i-1])
print(len(ans))
for i in ans:
    print(*i)