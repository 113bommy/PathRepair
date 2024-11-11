a = [int(i) for i in input().split()]
a.sort()
a[2] -= a[0]
a[1] -= a[0]
count = 0
if(a[2] == a[1]):
	print(max(a[2]-1,0))
elif(a[2] > a[1]):
	count += a[1]
	a[2] -= a[1]
	print(max((a[2]- 1)*2 + count,0))