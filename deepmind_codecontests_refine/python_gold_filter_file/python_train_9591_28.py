n,k=map(int,input().split())
b=list(map(int,input().split()))
p=b.count(1)
q=b.count(-1)
ans=-1
j=0
while(j<min(n,k)):
    c1=p
    c2=q
    i=j
    while(i<n):
        if b[i]==1:
            c1+=-1
        else:
            c2+=-1
        i+=k
    ans=max(ans,abs(c1-c2))
    j+=1
print(ans)

