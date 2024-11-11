S=int(input())
x=10**9+7
a=[0 for i in range(2001)]
a[3]=1
a[4]=1
a[5]=1
a[6]=2
for i in range(7,S+1):
    a[i]=(a[i-1]+a[i-3])%x
print(a[S])