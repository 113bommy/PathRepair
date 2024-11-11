# your code goes here
def predicate(x, m, a):
	rhs = 0
	for i in range(len(a)):
		cv = (m+(x-rhs))/a[i]
		#print(cv)
		if cv<-1e-8:
			return False
		rhs+= cv
	#print(rhs)
	if(x-rhs >= -1e-8):
		return True
	return False
		
n = int(input())
m = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = []
for i in range( n-1):
	c.append(a[i])
	c.append(b[i+1])
	
c.append(a[-1])
c.append(b[0])
#predicate(10, m, c)
lo = 0
hi = 1e10
i = 0
while i < 1000:
	mid = (hi+lo)/2
	if predicate(mid, m, c):
		hi = mid
	else:
		lo = mid
	i+=1
print(lo) if lo <= 1e9+1e-8 else print(-1)