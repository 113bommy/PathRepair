n = int(input())
a = list(map(int,input().split()))

for i in range(1,n):
	print(a)
	j = i -1
	v = a[i]
	while j >= 0 and a[j] > v:
		a[j+1] = a[j]
		j -= 1
	a[j+1] = v
print(a)
