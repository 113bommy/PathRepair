n = int(input())
arr = list(map(int,input().split()))
ind = []
maxx = max(arr)
for i in range(n):
	if arr[i]==maxx:
		ind+=[i]
ans = []
maxx = 0
for x in ind:
	t = arr[:]
	for i in range(x-1,-1,-1):
		if t[i]>t[i+1]:
			t[i] = t[i+1]
	for i in range(x+1,n):
		if t[i]>t[i-1]:
			t[i] = t[i-1]
	if sum(t)>maxx:
		maxx = sum(t)
		ans = t[:]
print(*ans)