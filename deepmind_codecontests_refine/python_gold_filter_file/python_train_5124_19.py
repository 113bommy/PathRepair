t=int(input())
for i in range(t):
    n=int(input())
    a=list(input())
    x=0
    k=n
    ans=0
    for j in range(n):
        if(a[j]=='A'):
            k=j
            break
    for j in range(k+1,n):
        if(a[j]=='A'):
            ans=max(ans,x)
            x=0
        else:
            x+=1
    ans=max(ans,x)
    print(ans)