# https://codeforces.com/contest/747/problem/A

n = int(input())
minDis = n - 1
a = 1
b = n

for i in range(2, n):
	if i * i > n:
		break
	if n % i == 0:
		if i <= n / i and n /i - i < minDis:
			a = i
			b = n/ i
			minDis = b - a
print(a, ' ',b)

