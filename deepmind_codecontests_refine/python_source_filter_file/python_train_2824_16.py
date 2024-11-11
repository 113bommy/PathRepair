n,k=map(int,input().split())
arr=list(map(int,input().split()))
if n==1:
	print(1)
	exit()
if n==2:
	if arr[0]==arr[1]:
		print(1)
	else:
		print(2)
	exit()
col=1
i=0
j=1
start=0
mm=1
c=1
ans=[]
while i<n and j<n:
	if arr[i]!=arr[j]:
		c+=1
		mm=max(mm,c)
		j+=1
		i+=1
	else:
		ans.append([mm,start,j])
		c=1
		i=j
		start=i
		j=j+1
ans.append([mm,start,j-1])
ans=sorted(ans,key=lambda item:item[0],reverse=True)
for i in range(len(ans)):
	s=set()
	for j in range(ans[i][1],ans[i][2]+1):
		s.add(arr[j])
	if len(s)>=k:
		print(ans[i][0])
		break
