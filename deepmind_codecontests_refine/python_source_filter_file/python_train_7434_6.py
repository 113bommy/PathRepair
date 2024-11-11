n, d = list(map(int, input().split()))
a = list(map(int, input().split()))
m = int(input())
s = 0
if m > n:
	s -= (m - n) * d
a.sort()
for i in range(n):
	s += a[i]
print(s)
