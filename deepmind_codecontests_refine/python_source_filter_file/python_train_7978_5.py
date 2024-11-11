n=int(input())
if n==1:
	print("0")
	exit()
s=input()
r,u,x,flag=0,0,0,0
for i in s:
	if i=='R':
		r+=1
	else:
		u+=1
	if r>u and flag==0:
		x+=1
		flag=1
	elif r<u and flag==1:
		x+=1
		flag=0
print(x-1)