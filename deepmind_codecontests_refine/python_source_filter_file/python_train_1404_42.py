a,k = map(int,input().split())
ls = list(map(int,input().split()))
nls = []
for i in ls:
	nls.append(i)
ls.sort()
ind = []
ins = 0
for i in range(a):
	if ls[i] < k and ins < k:
		if ins + ls[i]>k:
			break
		else:
			ins += ls[i]
			ind.append(nls.index(ls[i])+1)
			nls[nls.index(ls[i])] = "l"
print(len(ind))
for i in sorted(ind):
	print(i,end = " ")