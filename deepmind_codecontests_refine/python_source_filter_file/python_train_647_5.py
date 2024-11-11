from sys import stdin
input = stdin.buffer.readline
n = int(input())
*a, = map(int, input().split())
ans = 0
for i in range(31):
	s = 0
	for j in a:
		if j <= i:
			s = max(0, s + j)
		else:
			s = 0
	ans = max(ans, s - i)
print(ans)