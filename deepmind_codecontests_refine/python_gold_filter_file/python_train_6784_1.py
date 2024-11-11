a = input()
b = input()
pref = [0] * (len(a) - 1)
pyk = 0
for i in range(len(a) - 1):
	if a[i] != a[i + 1]:
		pyk += 1
		pref[i] = pyk
	else:
		pref[i] = pyk
chuj = 0
res = 0
for i in range(len(b)):
	if a[i] != b[i]:
		chuj += 1
tesame = 1
dupa = 1
for i in range(len(a) - len(b)):
	if i > 0:
		if (pref[i + len(b) - 1] - pref[i - 1]) % 2 != 0:
			dupa = 1 - dupa
		tesame += dupa
	else:
		if (pref[i + len(b) - 1]) % 2 != 0:
			dupa = 1 - dupa
		tesame += dupa
if chuj % 2 == 0:
	print(tesame)
else:
	print( len(a) - len(b) + 1 - tesame)