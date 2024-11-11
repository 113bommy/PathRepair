def main():
	n, m, k, x, y = map(int, input().split())
	x -= 1
	y -= 1

	if (n == 1):
		ever = [k // m for i in range(m)]
		k %= m
		for i in range(k):
			ever[i] += 1
		print(max(ever), min(ever), ever[y])
		return

	per_leng = m * (2 * n - 2)
	per_num = k // per_leng
	
	every_raw = [2 * per_num for i in range(n)]
	every_raw[0] -= per_num;
	if (every_raw[-1] == 2 * per_num):
		every_raw[-1] -= per_num
	k %= per_leng

	curr_raw = 0
	dire = 0
	while (k >= m):
		every_raw[curr_raw] += 1
		if (dire == 0):
			if (curr_raw + 1 < n):
				curr_raw += 1
			else:
				dire = 1
				curr_raw -= 1
		else:
			curr_raw -= 1

		k -= m



	if (k == 0):
		print(max(every_raw), min(every_raw), every_raw[x])
	else:
		spec = [every_raw[curr_raw] for i in range(m)]
		for i in range(k):
			spec[i] += 1
		all_arr = []
		for i in range(n):
			if (i != curr_raw):
				all_arr.append(every_raw[i])
			else:
				all_arr += spec
		print(max(all_arr), min(all_arr), end = " ")
		if (x == curr_raw):
			print(spec[y])
		else:
			print(every_raw[x])





main()