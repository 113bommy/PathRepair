n=int(input())
a=[int(i) for i in input().split(' ')]
M,m,k=a[0],a[0],a[0]
L,t,r,tm,tM=0,0,0,0,0
while n>0:
    n-=1
    if abs(M-a[r])>1 or abs(a[r]-m)>1:
        if L<r-t:
            L=r-t
        if abs(a[r]-m)<=1:
            t=tm
            M=m
        if abs(a[r]-M)<=1:
            t=tm
            m=M
    if M<=a[r]:
        M=a[r]
        if k==m:
            tm=r
        k=M
    if m>=a[r]:
        m=a[r]
        if k==M:
            tm=r
        k=m
    r+=1
if L<r-tm:
    L=r-tm
print(L)
