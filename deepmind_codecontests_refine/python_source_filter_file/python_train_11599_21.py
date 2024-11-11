st = list(input())
a = -1
for i in range(len(st)):
	if a == -1:
		if st[i] == "4":
			a = 1
		else:
			a = 4
			break
	elif a == 0:
		if st[i] == "4":
			a = 1
		elif st[i] == "1":
			a = 0
		else:
			a = 4
			break
	elif a == 1:
		if st[i] == "4":
			a = 2
		elif st[i] == "1":
			a = 0
		else:
			a = 4
			break
	elif a == 2:
		if st[i] == "1":
			a = 0
		else:
			a = 4
			break
if a > 3:
	print("NO")
else:
	print("YES")
