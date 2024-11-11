n, m = list(map(int,input().split()))
s = input().split()
t = input().split()

y = int(input())

for i in range(y):
	x = int(input())
	mn = x%n
	mm = x%m
	a = s[n - 1 if mn == 0 else (mn - 1)]
	b = t[m - 1 if mm == 0 else (mm - 1)]
	print(a + ' ' + b)