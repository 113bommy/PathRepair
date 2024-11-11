n = int(input())
dt = sorted([int(input()) for i in range(n)])

ans = 0
for i in range(n):
	ans += dt[i] * dt[-i-1]
print(ans%10007)