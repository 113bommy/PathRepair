n=int(input())
a=list(map(int,input().split()))
c=int()
if n==1:
    print(0)
else:
    if a[0]==1 and a[1]==2:
        c=1
    if a[n-1]==1000:
        t=True
    ma=int()
    for i in range(1,n):
        if a[i]-1==a[i-1]:
            c+=1
        else:
            c=0
        if ma<c:
            ma=int(c)
    if a[n-1]==1000 and a[n-2]==999:
        c+=1
    if ma<c:
        ma=int(c)
    print(max(0,ma-1))
