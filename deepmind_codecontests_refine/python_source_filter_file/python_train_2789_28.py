N=int(input())
b=list(map(int,input().split()))
c=[]
for i in range(N):
	c.append(b[i]**2)
print(((sum(b))**2-sum(c))/2)