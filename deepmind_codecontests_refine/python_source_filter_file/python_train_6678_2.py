from collections import Counter
def solve():
	n = int(input())
	arr = list(map(int, input().split(" ")))

	highest_freq_items = Counter(arr).most_common(1)[0]
	highest_freq = highest_freq_items[1]
	highest_freq_num = highest_freq_items[0]

	if (n - highest_freq) == 0:
		print(0)
		return

	print(n - highest_freq)
	index = arr.index(highest_freq_num)

	# Left Side
	for i in range(index - 1, -1, -1):
		if arr[i] == highest_freq_num:
			continue

		if arr[i] > highest_freq_num:
			print("2 {} {}".format(i + 2, i + 1))
		else:
			print("1 {} {}".format(i + 1, i + 2))

	# Right Side
	for i in range(index, n):
		if arr[i] == highest_freq_num:
			continue

		if arr[i] > highest_freq_num:
			print("2 {} {}".format(i + 1, i))
		else:
			print("1 {} {}".format(i, i + 1))

solve()