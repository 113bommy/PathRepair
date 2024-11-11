"""PROBLEM: http://codeforces.com/problemset/problem/330/A"""

size = list(map(int, input().split(" ")))

evil_strawberrys_rows = set()
evil_strawberrys_columns = set()

for i in range(size[0]):
	row = input()
	for j in range(size[1]):
		if row[j] == 'S':
			evil_strawberrys_rows.add(i)
			evil_strawberrys_columns.add(j)

answer = size[0] * size[1] - len(evil_strawberrys_rows) * len(evil_strawberrys_columns)
print(answer)