n = int (input())
a = list(map(int,input().split()))
d = {}
for i in range(n):
	x = i
	j = i
	count = 0
	while True:
		if j>=0 and a[j] >= a[j-1]:
			count+=1
		else:
			break
		j-=1
	while True:
		if x<len(a)-1 and a[x] >= a[x+1]:
			count+=1
		else:
			break 
		x+=1
	d[i] = count
print(max(d.values()))
