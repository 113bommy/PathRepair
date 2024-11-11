n = int(input())
a = list(map(int,input().split()))

if min(a) == max(a):
	print(0)
else:
	max1 = -float('inf')
	a.sort()
	count = 1
	for i in range(n-1):
		if a[i]==a[i+1]:
			count+=1
		else:
			count = 0
		max1= max(max1,count)
	print(n-max1) 

