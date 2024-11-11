from fractions import gcd

n = int(input())
ans = 1

for _ in range(n):
	i = int(input())
	ans = int(ans / gcd(ans, i) * i)

print(ans)