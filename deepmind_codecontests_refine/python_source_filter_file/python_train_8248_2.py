for t in range(int(input())):
	n = int(input())

	S = list(map(int, input().split()))
	S.sort()

	ans = -1

	for k in range(1, S[-1] + 1):
		newSet = set(S)

		for s in S:
			x = k ^ s

			if x not in newSet:
				break

			else:
				newSet.remove(x)

		if len(newSet) == 0:
			ans = k
			break

	print(ans)