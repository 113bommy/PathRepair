
n = int(input())
ar = [int(input()) for _ in range(n)]
for i in range(1,n):
	ar[i] += ar[i-1]

M = 1000000007
f = [1]
for i in range(1,1000000):
	f.append(f[-1]*i%M)

def C(n,k):
	return (f[n]*pow(f[k],M-2,M)%M)*pow(f[n-k],M-2,M)%M

dp = [1]*(n+4)
for i in range(1,n):
	dp[i] = C(ar[i]-1,ar[i-1])*dp[i-1]

print(dp[n-1])

#  C:\Users\Usuario\HOME2\Programacion\ACM