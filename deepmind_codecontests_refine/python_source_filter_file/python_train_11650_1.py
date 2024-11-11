# AOJ 0501: Data Conversion
# Python3 2018.6.29 bal4u

while True:
	n = int(input())
	if n == 0: break
	tbl = {}
	for i in range(n):
		a, b = input().split()
		tbl[a] = b
	ans = ''
	m = int(input())
	for i in range(m):
		a = input()
		ans += tbl[a] if a in tbl else a
	print(ans)
