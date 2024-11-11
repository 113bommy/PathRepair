for _ in range(int(input())):
	n = int(input())
	# l, r = map(int, input().split())
	# l = [list(map(int, input().split())) for i in range(n)]
	# l = list(map(int, input().split()))
	arr = [6,10, 14, 15, 21, 22]
	if n<31:
		print("NO")
	else:
		t = n-30
		if t == 6:
			print("YES")
			print(5, 6, 10, 15)
		elif t == 10:
			print("YES")
			print(6, 9, 10, 15)
		elif t == 14:
			print("YES")
			print(6, 7, 10, 21)
		else:
			print("YES")
			print(6, 10, 14, t)