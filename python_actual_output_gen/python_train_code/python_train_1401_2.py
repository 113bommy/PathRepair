n,m,k=map(int,input().split())
a=list(map(int,input().split()))
i=n
s=k
while(i>=0 and m>0):
    i-=1
    if(s<a[i]):
        m-=1
        s=k
    s-=a[i]
if(m==0):
    print(n-i-1)
else:
    print(n-i)
