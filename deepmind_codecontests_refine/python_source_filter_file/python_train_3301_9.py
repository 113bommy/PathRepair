R = lambda:map( int , input().split() )
n  = int(input())

arr = list(R())

m = min(arr)
mi = arr.index(m)
left = 0
right = 10**9
def checkFind(t):
	i = 0
	find = False
	while i < n:
		if (n * t) + i + 1 > arr[i] :
			find  = True
			break
		i += 1 
	return find
t = 10**9
	
while left < right:
	m = (left + right) // 2
	if checkFind(m):
		t = min(t,m)
		right = m-1
	else:
		left = m+1
i = 0
#print(t)
while i < n:
	if (n * t) + i + 1 > arr[i] :
		break
	i += 1 
print(i+1)







