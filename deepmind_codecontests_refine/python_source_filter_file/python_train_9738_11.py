import os
from math import*

n,k=map(int,input().split())
arr=input()
arr=list(arr)
a=list(filter(lambda x:x=="a",arr))
b=list(filter(lambda x:x=="b",arr))
x=""
if len(a)>=len(b):
	x="b"
else:
	x="a"
if k==0:
	ans=0
	count=1
	for i in range(n-1):
		if arr[i]==arr[i+1]:
				count+=1
		else:
			if ans<count:
				ans=count
				count=1
	if ans<count:
		ans=count
	print(ans)
else:
	fp=0
	ans=0	
	count=0
	brr=[0]
	checkpos=0
	for i in range(n):
		if arr[i]==x:
			count+=1
			brr.append(i)
		if count>k:
			count-=1
			if checkpos==0:	
				ans=i-brr[checkpos]	
			else:
				if ans<i-brr[checkpos]-1:
					ans=i-brr[checkpos]-1
			checkpos+=1
			fp=i
		#print(brr,ans,checkpos)
	#print(brr,ans)
	if len(brr)-1<=k:
		print(n)
	else:
		if ans<n-brr[-1-k]-1:
			ans=n-1-brr[checkpos]
		print(ans)


