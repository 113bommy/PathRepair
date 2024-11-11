t=int(input())
ans=[]
while t!=0:
    n=int(input())
    l=list(map(int,input().split()))
    zeroes=l.count(0)
    s=0
    c=0
    for i in range(0,len(l)):
        if l[i]==0:
            l[i]=1
            c=c+1

    for i in range(0,len(l)):
        s=s+l[i]
    if s<=0:
        s=abs(s)+1
    else:
        s=0
    
    ans.append(s+c)
    t=t-1
for i in range(0,len(ans)):

    print(ans[i])