
n,m,k = map(int,input().split())
mod = 10**9 + 7
if k == 1:
    print(pow(m,n,mod))

elif k == n:
    print(pow(m,(n+1)//2,mod))


elif k%2== 0:


    print(m%mod)
else:
    print(pow(m,2,mod))
