a=int(input())
b=list(map(int,input().split()))
b.sort()
count=0
l1=[]
for i in range(a):
	if b[i]<0:
		#list1.append(b[i])
		count+=1
if count%2==0:
	for j in range(count):
		 l1.append(abs(-1-b[j]))
	for k in range(a-count):
		 l1.append(abs(1-b[k+count]))
	#print(l1)
	print(sum(l1))
else:
	for j in range(count-1):
		 l1.append(abs(-1-b[j]))
	for k in range(a-count+1):
		 l1.append(abs(1-b[k+count-1]))
	print(sum(l1))	 
		 
		 