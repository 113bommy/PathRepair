def main():
	n = int(input())
	a = list(map(int, input()))
	b = list(map(int, input()))
	cnt = [0 for i in range(10)]
	for i in (b):
		cnt[i] += 1
	min_gotten = 0
	for i in a:
		for j in range(i, 10):
			if (cnt[j] > 0):
				cnt[j] -= 1
				break
		else:
			for j in range(1, i):
				if (cnt[j] > 0):
					cnt[j] -= 1
					break
			min_gotten += 1
	print(min_gotten)

	for i in (b):
		cnt[i] += 1
	max_given = 0
	for i in a:
		for j in range(i + 1, 10):
			if (cnt[j] > 0):
				cnt[j] -= 1
				max_given += 1
				break
		else:
			for j in range(1, i + 1):
				if (cnt[j] > 0):
					cnt[j] -= 1
					break
	print(max_given)

main()