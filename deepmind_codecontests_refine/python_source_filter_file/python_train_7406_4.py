n = int(input())
a = list(map(int, input().split()))

mstart = -1
mend = -1
start, end = -1, -1
cur = 0
ma = -1

for i in range(n):
	if(i == (n - 1) and a[i] == 1):
		mend = i
	if(a[i] == 1):
		cur += 1
		if(mstart == -1):
			mstart = i
	if(cur >= ma):
		ma = cur
		start = mstart
		end = mend

	if(a[i] == 0):
		end = i
		mstart = -1
		cur = 0


if(end != (n - 1) and start != 0):
	print(ma)
elif(end == (n - 1)):
	for i in range(n):
		if(a[i] == 1):
			ma += 1
		else:
			break
	print(ma)
else:
	for i in range(n - 1, -1, -1):
		if(a[i] == 1):
			ma += 1
		else:
			break
	print(ma)