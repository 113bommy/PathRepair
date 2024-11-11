n , m = map(int , input().split())
c=[]
for _ in range(m):
	a , b = map(int ,input().split())
	c.append((b,a))
c = sorted(c, key=lambda x:x[0] , reverse= True)
M = 0
print(c)
for i , j in c:
	if n <= 0:
		break
	s = min(n , j)
	M += s*i
	n = n-j
print(M)