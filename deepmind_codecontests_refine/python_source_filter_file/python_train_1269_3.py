n,m = map(int,input().split())
fib = [1,1]
mod = 10**9+7
for i in range(max(m,n)):
    fib.append((fib[-1]+fib[-2])%mod)
print((2*(fib[m-1]+fib[n-1]-1))%mod)