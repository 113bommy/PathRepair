for _ in range(int(input())):
	a = list(map(int, input().split()))
	a.sort()
	if a[0] != a[1] and a[0] != a[1] and a[1] != a[2]:
		print("NO")
	elif a[0] == a[1] and a[1] != a[2]:
		print("NO")
	else:
		print("YES")
		if a[0] == a[1] and a[1] == a[2]:
			print(str(a[0]) + " " + str(a[0]) + " " + str(a[0]))
		else:
			print(str(a[2]) + " " + str(a[1]) + " 1")
