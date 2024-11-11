n, m = map(int, input().split())
ans = True
f = [-1 for i in range(n)]
temp = []
for i in range(m):
	x, a, b = map(int, input().split())
	if x == 0:
		temp.append((a,b))
	else:
		f[a:b] = [1 for z in range(b - a)]
for (a,b) in temp:
	if set(f[a:b]) == {1}:
		ans = False
		break
	else:
		for k in range(a,b):
			if f[k] == -1:
				f[k] = 0
f.pop(0)
print(f)

if ans:
	print("YES")
	l = []
	if ans == True:
		current = 1001
		l.append(current)
		for x in f:
			if x == 0:
				current -= 1
				l.append(current)
			else:
				l.append(current)
	print(*l)
else:
	print("NO")

