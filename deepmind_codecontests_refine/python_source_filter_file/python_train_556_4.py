a =[]
for i in range(3):
	a.append(list(map(int,input().split())))

for n in range(1,10**5):
	s = n+ a[0][1] + a[0][2]
	k = s - a[1][0] - a[1][2]
	w = s - a[2][0] - a[2][1]
	if n+k+w==s:
		a[0][0] = n
		a[1][1] = k
		a[2][2] = w
		break
for i in range(3):
	print(*a[i])
	