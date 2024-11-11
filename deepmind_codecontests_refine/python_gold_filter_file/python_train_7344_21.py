R = lambda:list(map(int,input().split()))
n,b,d = R()
k = list(filter(lambda x: x<=b,R()))
c,h=0,0
for i in k:
	c+=i
	if c>d:
		h+=1
		c=0
print(h)