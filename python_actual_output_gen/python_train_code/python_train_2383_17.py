n=int(input())
t=int(input())
c=0
while(t%n==0):
	t=t//n
	c+=1
if c==0 or t!=0:
	print("NO")
else:
	print("YES")
	print(c-1)