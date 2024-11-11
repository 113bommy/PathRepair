for i in range(int(input())):
	n, m = list(map(int, input().split()))
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	b.sort()
	found = False
	for num in a:
		if num in b:
			print("YES")
			print(f"1 {num}")
			found = True
	if not found:
		print("NO")