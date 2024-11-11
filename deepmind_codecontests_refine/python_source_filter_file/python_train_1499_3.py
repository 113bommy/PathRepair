#ossan
n = int(input())
res = {}
li = []
for i in range(n):
	li.append(list(input().split()))
	li[-1][1] = int(li[-1][1])
for i in li:
	if i[0] not in res:
		res[i[0]] = i[1]
	else:
		res[i[0]] += i[1]
k = max(res, key = res.get)
li1 = {k:0}
li2 = []
for i in res:
	if res[i] == res[k]:
		li1[i] = 0
		li2.append(i)
if len(li1) == 1:
	print(k)
else:
	for i in li:
		if i[0] in li2:
			li1[i[0]] += i[1]
			if li1[i[0]] == res[k]:
				print(i[0])
				break

