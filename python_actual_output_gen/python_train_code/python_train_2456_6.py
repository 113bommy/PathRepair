from sys import stdin
input = stdin.buffer.readline

n = int(input())
*a, = map(int, input().split())
s1 = sum(a[i] for i in range(0, n, 2))
s2 = sum(a[i] for i in range(1, n, 2)) + a[0]
ans = max(s1, s2)
for i in range(0, n, 2):
	s1 += a[i] - a[(i + 1) % n]
	ans = max(ans, s1)
for i in range(1, n, 2):
	s2 += a[i] - a[(i + 1) % n]
	ans = max(ans, s2)
print(ans)

