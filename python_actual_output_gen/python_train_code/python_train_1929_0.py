from sys import stdin
input = stdin.readline

n = int(input())
res = 0
for i in range(n):
	k, a = (int(x) for x in input().split())
	if k == 0:
		res = max(res, 1)
	i = 0
	x = 1
	while a > x:
		i += 1
		x *= 4
	res = max(res, k + i)
print(res)
