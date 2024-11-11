n, m = [int(x) for x in input().split(' ')]

unordered = []
count = 0
ordered_status = [0] * n
for i in range(m):
	t, l, r = [int(x) for x in input().split(' ')]
	if t == 1:
		for j in range(l, r):
			ordered_status[j] = 1
	else:
		unordered.append([l, r])
		count += 1

for el in unordered:
	l = el[0]
	r = el[1]
	if sum(ordered_status[l:r]) == (r-l):
		print('NO')
		exit()
	# else:
	# 	for j in range(l, r):
	# 		ordered_status[j] = 0

print('YES')
solution = [10000] * (n+1)
for i in range(1, n+1):
    if ordered_status[i-1] == 1:
        solution[i] = solution[i-1] + 1
    else:
        solution[i] = solution[i-1] - 1
print(" ".join([str(solution[x]) for x in range(1, n+1)]))
