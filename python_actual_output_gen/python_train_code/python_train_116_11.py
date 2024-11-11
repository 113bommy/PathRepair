n=int(input())
x=10**9+7
res=1
for i in range(1,n+1):
        res=res*i
        res=res%x
print(res-2**(n-1)%x)
