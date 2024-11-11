n = int(input())
a = [int(x) for x in input().split()]
s=sum(a)
x=[1]
arr=[a[0]]
flag=0
for i in range(1,len(a)):
	if a[x[0]-1]>=2*a[i]:
		x.append(i+1)
		arr.append(a[i])
		if sum(arr)>s//2:
			flag=1
			break

#print(x)
if len(a)==2:
	if a[0]>a[1]:
		print(1)
		print(1)
	else:
		print(0)
elif flag:	
	print(len(x))
	for i in x:
		print(i,end=" ")
		print()
else:
	print(0)		
