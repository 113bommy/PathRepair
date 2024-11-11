
n=int(input())
arr=list(map(int,input().split()))
n1=list(filter(lambda x:x<0,arr))
n2=list(filter(lambda x:x>0,arr))
z=0
print("1",end=' ')
print(n1[0])
if len(n2)>0:
	print(len(n2),end=' ')
	for x in n2:
		print(x,end=' ')
	print()
else:
	z=1
	print("2",end=' ')
	print(n1[1],n1[2],end=' ')
	print()
if z==1:
	print(n-3,end=' ')
	for i in range(3,len(n1)):
		print(n1[i],end=' ')
	print("0")
else:
	print(n-1-len(n2),end=' ')
	for i in range(1,len(n1)):
		print(n1[i],end=' ')
	print("0")

