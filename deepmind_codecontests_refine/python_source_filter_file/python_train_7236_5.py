x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())
xs = [x1, x2, x3]
ys = [y1, y2, y3]
ycount = 1
xcount = 1
for i in range(3):
	xcount = max(xcount, xs.count(xs[i]))
	ycount = max(ycount, ys.count(ys[i]))
ret = 3
if xcount == 3 or ycount == 3:
	print(1)
elif xcount == 2 or ycount == 2:
	if xcount == 2:
		for i in range(2):
			for j in range(1, 3):
				if xs[i] == xs[j]:
					a = i
					b = j
		for i in range(3):
			if i != a and i != b:
				c = i
		if ys[a] < ys[c] < ys[b] or ys[a] > ys[c] > ys[b]:
			ret = 3
		else:
			ret = 2
	if ycount == 2:
		for i in range(2):
			for j in range(1, 3):
				if ys[i] == ys[j]:
					a = i
					b = j
		for i in range(3):
			if i != a and i != b:
				c = i
		if xs[a] < xs[c] < xs[b] or xs[a] > xs[c] > xs[b]:
			ret = min(ret, 3)
		else:
			ret = min(ret, 2)
	print(ret)
else:
	print(ret)

