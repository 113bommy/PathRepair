n = int(input())
s1 = [int(i) for i in input()]
s2 = [int(i) for i in input()]
a = [[] for i in range(4)]
for i in range(n):
	a[s2[i] * 2 + s1[i]].append(i + 1)

def cal(a0, a2):
	nota0 = len(a[0]) - a0
	nota2 = len(a[2]) - a2
	nota1 = a0 + a2 - nota0
	a1 = len(a[1]) - nota1
	a3 = n // 2 - a0 - a1 - a2
	nota3 = len(a[3]) - a3
	if len(a[0]) < a0: return None
	if len(a[2]) < a2: return None
	if len(a[1]) < a1 or a1 < 0: return None
	if len(a[3]) < a3 or a3 < 0: return None
	if a1 + a3 != nota2 + nota3: return None
	return (a0, a1, a2, a3)

ans = None
for i in range(n // 2 + 1):
	if ans != None: break
	for j in range(n // 2 + 1):
		ans = cal(i, j)
		if ans != None: break

if ans == None:
	print(-1)
else:
	res = []
	a0, a1, a2, a3 = ans
	for i in range(a0): res.append(a[0][i])
	for i in range(a1): res.append(a[1][i])
	for i in range(a2): res.append(a[2][i])
	for i in range(a3): res.append(a[3][i])
	print(*res)
