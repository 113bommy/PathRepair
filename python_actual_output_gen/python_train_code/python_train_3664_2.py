def prob(l, r, p) :
	d = r - l + 1
	x = d // p
	l2 = l + x * p
	if l2 > r :
		return x / d
	modl = l2 % p
	modr = r % p
	if modl == 0 and modr == 0 or modl > modr :
		x += 1
	return x / d

sLine = input()
sSplit = sLine.split()
n = int(sSplit[0])
p = int(sSplit[1])
v = []
for i in range(n) :
	sLine = input()
	sSplit = sLine.split()
	v.append([int(sSplit[0]), int(sSplit[1])])
fSum = 0.0
for i in range(-1, n-1) :
	f = 1 - (1 - prob(v[i][0], v[i][1], p)) * (1 - prob(v[i+1][0], v[i+1][1], p))
	fSum += f
print('{0:.6f}'.format(fSum * 2000))
