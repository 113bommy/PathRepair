n=int(input())
arr=[]
for i in range(6):
	arr.append(0)
ar=[]
for i in range(n):
	ar.append(input())
for i in ar:
	if i=="purple":
		arr[0]=1
	elif i=="green":
		arr[1]=1	
	elif i=="blue":
		arr[2]=1
	elif i=="orange":
		arr[3]=1	
	elif i=="red":
		arr[4]=1	
	elif i=="yellow":
		arr[5]=1	
ans=[]
for i in range(6):
	if arr[i]==0:
		if i==0:
			ans.append("Power")
		elif i==1:
			ans.append("Time")
		elif i==2:
			ans.append("Space")	
		elif i==3:
			ans.append("Soul")
		elif i==4:
			ans.append("Reality")
		elif i==5:	
			ans.append("Mind")
print(len(ans))
for i in ans:
	print(i)
				