n=int(input())
a=list(map(int,input().split()))
odd=[]
even=[]
for i in a:
	if(i % 2==0):
		even.append(i)
	else:
		odd.append(i)
o=len(odd)
e=len(even)
c=0
if(o>e):
	c=1
elif(e>o):
	c=2
else:
	c=1
if(c==1):
	print("First")
else:
	print("Second")
