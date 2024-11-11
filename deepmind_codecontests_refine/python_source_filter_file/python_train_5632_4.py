n, m = map(int,input().split())
v = list(map(int,input().split()))

d = {}
for i in range(1,101):
	d[i] = 0
for i in v:
	d[i] += 1
# print(d)

if n > m:
	print(0)
else:
	possible = m // n
	flag = False
	ret = 0
	while possible > 0:
		count = 0
		for value in d.values():
			count += value//possible
			if count == n:
				flag = True
				ret = possible
			if flag:
				break
		if flag:
			break
		else:
			possible -= 1
	if flag:
		print(ret)
	else:
		print(0)