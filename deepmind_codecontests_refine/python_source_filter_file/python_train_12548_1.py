a=[]

for i in range(2,1000):
	pr=1
	for j in range(2,i):
		if(i%j==0):
			pr=0
	if pr == 1:
		a.append(i)

def gcd(x,y):
	if(y==0):
		return x
	return gcd(y,x%y)

cur=1
n=int(input())
if(n==2):
	print(-1)
	exit()
for i in range(n):
	#print(a[i])
	cur=cur*a[i]

b=[]

for i in range(n):
	print(cur/a[i])
	#b.append(cur/a[i])