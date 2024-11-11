x = int(input())
for i in range(x):
	a = int(input())
	k = 0
	if x > 7:
		t = int(a/7)
		a = a - a*t
		k = k + t
	if a > 0:
		a = 0
		k = k + 1
	print(k)