n,k=map(int,input().split())
a=list(map(int,input().split()))


for j in range(k):
    b=[0]*n
    for i in range(0,n):
        l=max(0,i-a[i])
        r=min(n-1,i+a[i])
        b[l]+=1
        if(r+1<n):
            b[r+1]-=1
    for i in range(1,n,1):
        b[i]+=b[i-1]
    if a==b:
        break
    a=b

print(' '.join(map(str,a)))