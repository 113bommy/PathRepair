n,x = map(int,input().split())
arr = list(map(int,input().split()))
if sum(arr)+(n-1)== x:
	print("YES")
else:
	print("NO")
