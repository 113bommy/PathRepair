n,k = map(int,input().split())
arr = list(map(int,input().split()))
for i in range(n):
	if arr[i]<0:
		arr[i] *=-1
		k -=1
	if k==0:
		break
arr.sort()
if k//2!=0:
	arr[0]*=-1
print(sum(arr))