for _ in range(int(input())):
	n = int(input())
	# a = map(int, input().split())
	# l1 = list(map(int, input().split()))
	# l2 = list(map(int, input().split()))

	arr = []

	for i in range(n):
		arr.append(i+1)

	print(*arr)