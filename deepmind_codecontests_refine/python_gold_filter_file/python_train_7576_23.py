import fractions
N = int(input())
a = list(map(int,input().split()))
lcm = a[0]
for i in range(1,N):
	lcm = lcm*a[i]//fractions.gcd(lcm,a[i])

b = [0]*N

ans = 0
for i in range(N):
	ans += lcm//a[i]
print(int(ans%(10**9+7)))

