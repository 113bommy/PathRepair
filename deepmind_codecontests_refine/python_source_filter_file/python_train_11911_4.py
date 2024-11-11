n = int(input())
arr = [int(x) for x in input().split()]

d = {}

for i in range(n):
	if arr[i] not in d.keys():
		d[arr[i]] = []
	d[arr[i]].append(i)
ans = []
for k in list(d.keys()):
	a = d[k]
	if len(a)==1:
		ans.append([k,0])
	else:
		o = a[1]-a[0]
		f = 0
		for i in range(0,len(a)-1):
			if a[i+1]-a[i] != o:
				f = 1
				break
		if f==0:
			ans.append([k,o])
print(len(ans))
for i in ans:
	print(*i)

