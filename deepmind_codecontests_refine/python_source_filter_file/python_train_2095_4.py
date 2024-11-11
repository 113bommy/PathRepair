from sys import stdin, stdout
n = sum([int(x) for x in stdin.readline().split()])
x = [int(x) for x in  stdin.readline().split()]
t = [int(x) for x in  stdin.readline().split()]
ans = [[i, 0] for i in range(n) if t[i] == 1]
l = 0
r = 0
if len(ans) >= 2:
  r = 1
ans[0][1]+= ans[0][0]
for i in range(ans[0][0] + 1, n):
	if t[i] == 1:
		l = r
		if r != len(ans) - 1:
			r += 1
	else:
		if abs(x[ans[l][0]] - x[i]) >= abs(x[ans[r][0]] - x[i]):
			ans[l][1] += 1
		else:
			ans[r][1] += 1
for a in ans:
  stdout.write(str(a[1])+ ' ')
