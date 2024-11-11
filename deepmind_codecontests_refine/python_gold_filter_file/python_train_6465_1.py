n=int(input())
arr=list(map(int,input().split()))
ans=[]
arrr=[]
for i in range(n):
	if(i==0):
		arrr.append(arr[i])
	else:
		arrr.append(arr[i]-arr[i-1])
for i in range(1,n,1):
	if(arrr[i:n]==arrr[0:n-i]):
		ans.append(i)
ans.append(n)
print(len(ans))
print(*ans)