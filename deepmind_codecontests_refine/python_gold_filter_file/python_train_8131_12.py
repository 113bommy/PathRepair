tmp=input().split()
n=int(tmp[0])
k=int(tmp[1])
s=1
tmp=input().split()
arr=[]
for i in tmp:
	arr.append(int(i))
arr.sort()
if(n==1):
	if(k>=1):
		print(arr[0])
		s+=1
	while(s<=k):
		print("0")
		s+=1
else:
	tmp=0
	for i in range(n-1):
		if((arr[i]!=arr[i+1] or i==n-2) and s<=k):
			print(arr[i]-tmp)
			tmp=arr[i]
			s+=1
	if(arr[n-1]!=arr[n-2] and s<=k):
		print(arr[n-1]-arr[n-2])
		s+=1
	while(s<=k):
		print("0")
		s+=1