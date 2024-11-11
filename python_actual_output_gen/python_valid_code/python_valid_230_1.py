l1=list(map(int,input().split()))
l2=list(map(int,input().split()))
if(l1[1]>l1[2]):
	print(l1[0])
else:
	sum=0
	for i in l2:
		if i<l1[1]:
			sum+=1
	if sum%2==0:
		print(sum/2)
	else:
		print((sum//2)+1)