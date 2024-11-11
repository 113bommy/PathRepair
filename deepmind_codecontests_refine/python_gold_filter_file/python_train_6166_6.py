n,m=map(int,input().split())
arr=[]
# mid=""
for i in range(n):
	s=input().strip()
	arr.append(s)
d={}
for i in range(len(arr)):
	d[arr[i]]=i
visited=[0]*(n)
# if m%2==0:
start=""
end=""
for i in range(len(arr)):
	if visited[i]==0:
		temp=arr[i]
		temp=temp[::-1]
		if temp in d and d[temp]!=i:
			start+=arr[i]
			end=arr[d[temp]]+end
			visited[i]=1
			visited[d[temp]]=1
# print(start,end)
flag=False
for i in range(len(arr)):
	if visited[i]==0:
		temp=arr[i]
		temp=temp[::-1]
		if  temp==arr[i]:
			# print(temp)
			start+=temp
			ans=start+end
			print(len(ans))
			print(start+end)
			flag=True
			break
if not flag:
	print(len(start+end))
	print(start+end)
# else:

	# print(start+end)