def solve(n):
	arr[1]=1
	arr[2]=2
	for i in range(n+1):
		arr[i]=2*(arr[i-1])-arr[i-2]+1
	#return arr[n]


t=int(input())
for i in range(t):
	n,k=map(int,input().split())
	arr=[False]*(n+1)
	solve(n)
	if k in arr:
		p=arr.index(k)
		print("a"*(n-(p+1))+"b"+"a"*(p-1)+"b")
	else:
		for j in range(len(arr)):
			if arr[j]>k:
				a=k-arr[j-1]
				b=arr[j-1]
				p=j-1
				break

		print("a"*(n-(p+1))+"b"+"a"*((p+1)-(a+1)-1)+"b"+"a"*a)
		#+'b'+'a'*(p-1)+'b')

#print(arr)