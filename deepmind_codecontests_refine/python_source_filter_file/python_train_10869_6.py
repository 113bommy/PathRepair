n = int(input())
a = list(map(int,input().split()))
z = a[1]-a[0]
m,s = 1,2
for i in range(2,len(a)):
	x = abs(a[i]-a[i-1])
	if x<z:
		m = i
		s =i+1
		z = x
if abs(a[0]-a[n-1])<z:print(n,1)
else:print(m,s)