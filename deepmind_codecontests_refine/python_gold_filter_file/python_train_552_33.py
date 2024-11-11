def greater(a, b):
	if(a[0] > b[0]):
		return 0
	elif(a[0] == b[0]):
		if(a[1] < b[1]):
			return 0
		else:
			return 1
	else:
		return 1

n, k = map(int,input().split())
vals = []
for _ in range(n):
	x, y = map(int, input().split())
	vals.append((x, y))

for i in range(n-1):
	for j in range(n-i-1):
		if(greater(vals[j],vals[j+1])):
			vals[j], vals[j+1] = vals[j+1], vals[j]
rank = [0]*n
rank[0] = 1
val = 2
pos = 0
for i in range(1,n):
	if(vals[i][0] == vals[i-1][0] and vals[i][1] == vals[i-1][1]):
		rank[pos]=val
		val+=1
	else:
		pos+=1
		rank[pos]=val
		val+=1

for i in range(n):
	if(k <= rank[i]):
		if(i == 0):
			print(rank[i])
			break
		else:
			print(rank[i]-rank[i-1])
			break