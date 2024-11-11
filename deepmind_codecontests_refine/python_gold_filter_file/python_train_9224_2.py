x = int(input())
a = []
for i in range(x):
	a.append(input())
for i in range(x):
	k = 0
	for j in range(i,-1,-1):
		if j == i:
			continue
		if (a[i]==a[j]):
			k = k+1
	if k == 0:
		print("No")
	else:
		print("Yes")