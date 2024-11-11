n, m = map(int, input().split())
a = list(map(int, input().split()))
l = [int(input()) for i in range(m)]

invalid = -1
ans = [invalid]*n
s = set()
for i in range(n-1, -1, -1):
	s.add(a[i])
	ans[i] = len(s)

for i in range(m):
	out = ans[l[i]-1]
	if out != invalid:
		print(ans[l[i]-1])