import math
def isTriangle(n):
	a = math.sqrt(2*n)
	b = math.floor(a)
	if b*(b+1) == 2*n:
		return True
	else:
		return False

def Triangle(m):
	return (m*(m+1))//2

N = int(input())
t = 0
for i in range(1,int(math.sqrt(N))+1):
	a = Triangle(i)
	b = N - a
	if isTriangle(b):
		print("YES")
		t = 1
		break
if t == 0:
	print("NO")



