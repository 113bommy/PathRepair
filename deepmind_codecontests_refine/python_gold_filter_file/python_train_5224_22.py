n = int(input())
s = input()
x=s[-1::-1]
a=[]
s=list(s)
x=list(x)
for i in range(10):
	a.append(0)
for i in s:
	if(i=='L'):
		for j in range(10):
			if(a[j]==0):
				a[j]=1
				break
	elif(i=='R'):
		for j in range(9,-1,-1):
			if(a[j]==0):
				a[j]=1
				break
	else:
		a[int(i)]=0
	
	
s=""
for i in a:
	s+=str(i)
print(s)