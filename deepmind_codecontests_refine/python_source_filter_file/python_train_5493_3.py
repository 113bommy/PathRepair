num=int(input())
less=0
ind=0
flag=0
arr=[]
for i in range(0,num):
	n=str(input())
	arr.append(n)
m=1
for i in range(0,num):
	for j in range(i+1,num):
		if len(arr[i])>len(arr[j]):
			temp=arr[i]
			arr[i]=arr[j]
			arr[j]=temp
while m<=num-1:
	k=arr[m-1].find(arr[m])
	if k==-1:
		print ("NO")
		flag=1
		break
	m=m+1
if flag!=1:
	print ("YES")
	
	for i in range(0,num):
		print(arr[i])
