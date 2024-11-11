n = int(input())
d = list(map(int, input().split()))
answer = []
while not all(i == d[0] for i in d):
	i = max(range(n), key = lambda x: d[x])
	max1 = d[i]
	d[i] = 0
	j = max(range(n), key = lambda x: d[x])
	max2 = d[j]
	d[j] = 0
	z = max(range(n), key = lambda x: d[x])
	if max1 == max2 and max1 == d[z]:
		for t in range(n):
			if t != i and t != j and t != z:
				break
		if all(d[v] == d[t] for v in range(n) if v != i and v != j and v != z) and d[t] < max1:
			d[i] = max1 -1
			d[j] = max2 - 1
			d[z] -= 1
			answer.append(''.join('1' if k == i or k == j or k ==z else '0' for k in range(n)))
			continue
	#print(i, j, max1, max2)
	d[i] = max(max1 - 1, 0)
	d[j] = max(max2 - 1, 0)
	answer.append(''.join('1' if k == i or k == j else '0' for k in range(n)))
print(d[0])
print(len(answer))
for i in answer:
	print(i)