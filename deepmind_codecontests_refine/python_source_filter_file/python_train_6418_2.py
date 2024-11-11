n=int(input())
arr=list(map(int,input().split()))
a=b=0
for i in arr:
	if arr[i]>0:
		a+=arr[i]
	else:
		b+=arr[i]
print(a-b)