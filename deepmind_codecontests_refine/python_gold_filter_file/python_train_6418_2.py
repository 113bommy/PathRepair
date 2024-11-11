n=int(input())
arr=list(map(int,input().split()))
a=b=0
for i in range(n):
	if arr[i]>0:
		a+=arr[i]
	else:
		b+=arr[i]
print(a-b)