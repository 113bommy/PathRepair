a=list(map(int,input().split()))

ma=0
for i in range(14):
    b=[]
    ans=0
    for k in range(len(a)):
        b.append(a[k])
    if a[i]<14:
        b[i]=0
        for j in range(a[i]):
            b[int((i+j+1)%14)]+=1
        for i in range(len(b)):
            if b[i]%2==0:
                ans+=b[i]
        ma=max(ma,ans)
        
    else:
        b[i]=0
        p=a[i]//14
        for j in range(14):
            b[j]+=p
        for j in range(a[i]):
            b[int((i+j+1)%14)]+=1
        for i in range(len(b)):
            if b[i]%2==0:
                ans+=b[i]
        ma=max(ma,ans)
print(ma)