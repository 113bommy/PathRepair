n,x=map(int,input().split())
a=list(map(int,input().split()))
count=0
for i in range(1,n):
    if a[i-1]<0:
        a[i-1]=0
    b=a[i-1]+a[i]
    if b>x:
        a[i]-=b-x
        count+=b-x
print(count)