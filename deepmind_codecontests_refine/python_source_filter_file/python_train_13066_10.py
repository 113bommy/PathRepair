n = int(input())
fm = 0
a = list(map(int, input().split()))
s = set()
ans = list()

for i in range(0, n):
	if (a[i] in s):
		s.clear()
		ans.append(fm + 1)
		ans.append(i + 1)
		fm = i + 1
		continue
	s.add(a[i])
if (len(ans) == 0):
	print(-1)
else:
	ans[-1] = n;
	print(len(ans))
	for i in range(0, len(ans), 2):
		print(ans[i], ans[i + 1])