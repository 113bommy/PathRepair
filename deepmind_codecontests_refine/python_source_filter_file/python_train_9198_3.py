n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
j=0
c=0
for i in range(k):
    b=[a[i-c]]
    for l in range(n-j,n):
        b.append(a[l])
    print(j+1,*b)
    if i-c==n-j-1:
        c+=n-j
        j+=1