n = int(input(''))
a = list(map(int,input().split()))
a.sort()
print(a)
count = 0
for i in range(0,n-1):
	if i%2 == 0:
		count += a[i+1] - a[i]
print(count)