def check(j):
	for i in range(0, len(arr), 2):
		for k in range(arr[i] + j, arr[i + 1] + j):
			if lis[k] != 0:
				return True
	return False 
p, q, l, r = map(int, input().split())
lis = [0]*2001
while p:
	p -= 1 
	a, b = map(int, input().split())
	lis[a] += 1 
	lis[b + 1] -= 1 
for k in range(1, len(lis)):
	lis[k] = lis[k] + lis[k - 1]
arr = []
while q:
	q -= 1
	c, d = map(int, input().split())
	arr.append(c)
	arr.append(d)
arr.sort()
count = 0
for j in range(l, r + 1):
	if check(j):
		#print(j)
		count += 1 
print(count)