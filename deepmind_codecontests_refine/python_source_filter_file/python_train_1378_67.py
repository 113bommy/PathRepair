
class A:
	def findAB(self,x):
		if x==2:
			print(1,1)
		if x>=2:
			print(1,x-1)

# A.findAB()
	


a=A()
t=int(input())
for i in range(t):
	x=int(input())
	a.findAB(x)