n=int(input())
a=list(map(int,input().split()))
m=a[0]
a=a+a
for i in range(1,2*n):
    if a[i]==1:
        a[i]+=a[i-1]
        m=max(a[i],m)
print(m)