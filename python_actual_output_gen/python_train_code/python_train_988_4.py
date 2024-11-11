# your code goes here
n,k = (int(t) for t in input().split())
a = [int(i) for i in input().split()]

temp = a[0]
longest = 0
streak = 0
idx = 0
while idx < n:
	if idx > 0:
		if temp != a[idx]:
			streak+=1
			longest = max(longest, streak)
		else:
			longest = max(longest, streak)
			streak = 1
		temp = a[idx]
	else:
		streak+=1
	idx+=1
	
print(longest)


