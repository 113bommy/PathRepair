n = int(input())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))
l1.reverse()
l2.reverse()
o = [0] * (n + 1)
pos = [[0, 0] for i in range(n + 1)]
for i in range(n):
	pos[l1[i]][0] = i
	pos[l2[i]][1] = i
i = n - 1
was = [0] * (n + 1)
bound = n - 1
while i >= 0:
	was[l1[i]] = 1
	car = l1[i]
	pos2 = pos[car][1]
	if pos2 < i:
		bound = min(bound, i - 1)
		while bound > pos2:
			if not was[l2[bound]]:
				o[l2[bound]] = 1
			bound -= 1
	i -= 1
print(o.count(1))