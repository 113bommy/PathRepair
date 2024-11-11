n,k=map(int,input().split())
j,check,sum=0,0,0
a=[int(s) for s in input().split()]
a.sort()
while k:
    k-=1
    check=0
    while j<n and a[j]-sum<=0:
        j+=1
    if j==n:
        print(0)
    else:
        print(a[j]-sum)
        sum+=a[j]
        j+=1