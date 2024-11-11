n=int(input())
arr=[]
for i in range(n):
	x=list(map(int,input().split()))
	arr.append((x[0],x[1]))
arr.sort()
ans=0
m=arr[0][1]
for i in range(1,n):
	if arr[i][1]<m:
		ans+=1
	m=max(arr[i][1],m)
print(ans)
