s = list(map(int, input().split(',')))
d = list({i : 1 for i in s}.keys())
d.sort()
print(d)
f = False
ans = ''
for i in range(len(d) - 1):
	if d[i + 1] - d[i] == 1 and f:
		continue
	elif d[i + 1] - d[i] == 1 and (not f):
		ans += '{}-'.format(d[i])
		f = True
	elif d[i + 1] - d[i] != 1 and f:
		ans += '{},'.format(d[i])
		f = False
	else:
		ans += '{},'.format(d[i])
ans += str(d[-1])
print(ans)
