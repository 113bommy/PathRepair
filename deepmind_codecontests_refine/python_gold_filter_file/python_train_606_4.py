n, m = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]
y = [int(i) for i in input().split()]
mod = 1000000007
xtot = 0
ytot = 0
for i in range(n):
	xtot += (2*i-n+1)*x[i]
	xtot %= mod
for i in range(m):
	ytot += (2*i-m+1)*y[i]
	ytot %= mod
print(int((xtot*ytot)%mod))