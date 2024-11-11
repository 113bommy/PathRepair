import collections
n=int(input())
a=[int(i) for i in input().split()]
d=collections.Counter(a)
c=0
m=0
for i in a:
    if d[i]==1:
        c+=1
    elif d[i]>=3:
        m+=1
if c%2!=0 and m==0:
    print("NO")
else:
    l=0
    ans=[]
    print("YES")
    for i in range(0,n):
        if d[a[i]]==1 and l==0:
            ans.append("A")
            l+=1
        elif d[a[i]]==1 and l==1:
            ans.append("B")
            l+=1
        else:
            ans.append("A")
    if c==1:
        for i in range(0,n):
            if d[a[i]]>=3:
                ans[i]="B"
                break
    print(*ans,sep="")
