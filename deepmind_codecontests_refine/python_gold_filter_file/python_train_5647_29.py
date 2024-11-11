# import sys
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

# # from collection import defaultdict
# # import math

t = int(input())

for _ in range(t):
	n, m = map(int, input().split())

	mat = []
	flag = True
	count_w = 0
	count_b = 0
	for i in range(n):
		row = []
		for j in range(m):
			if flag:
				if j % 2 == 0:
					row.append('B')
					count_b += 1
				else:
					row.append('W')
					count_w += 1

			else:
				if j % 2 == 0:
					row.append('W')
					count_w += 1

				else:
					row.append('B')
					count_b += 1

		flag = not flag

		mat.append(row)

	if count_b - count_w != 1:
		for j in range(m):
			if mat[n - 2][j] == 'B':
				mat[n - 1][j] = 'B'
				break

	for i in range(n):
		row = mat[i]
		print(''.join(row))