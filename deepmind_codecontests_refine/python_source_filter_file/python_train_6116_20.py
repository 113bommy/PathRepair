a=[int(i) for i in input().split()]
n=a[0]
m=a[1]
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
ans=[]
for i in range(len(a)):
	if(a[i] in b):
		ans.append(a[i])
if(len(ans)==0):
	print("nothing")
else:
	for i in ans:
		print(i,end=' ')
	print()