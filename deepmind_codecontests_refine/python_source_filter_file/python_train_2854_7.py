n = int(input())
v = [int(x) for x in input().strip().split()]
start = 0
a = 2
i=0
while i<n:
	if n==1:
		a = 1
		break 
	if n==2:
		a=2
		break
	if not v[i]==v[i-1]+v[i-2]:
		start=i
		i+=2
	else:
		a = max(a,i-start+1)
		i+=1
print(a)
