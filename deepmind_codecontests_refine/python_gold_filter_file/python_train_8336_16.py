from collections import Counter
n=int(input())
arr=list(map(int,input().split()))
c=Counter(arr)
arr1=[]
for i in range(n):
	for j in range(0,31):
		x=(2**j)-arr[i]
		if(c[x]>=2) or (c[x]==1 and x!=arr[i]):
			arr1.append(arr[i])
			break
print(len(arr)-len(arr1))
