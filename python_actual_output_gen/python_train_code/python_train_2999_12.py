x = input()
t = int(x)
k = 0
i = 0
if t%10 == 0:
	for i in range(len(x)):
		if t%10 == 0:
			t = int(t/10)
		else:
			break
r = str(t)
for i in range(int(len(r)/2)):
	if r[i] == r[len(r)-i-1]:
		continue
	else:
		k = 1
		break
if i == int(len(r)/2) - 1 and k == 0 or i == 0 and k == 0:
	print("YES")
else:
	print("NO")