n = int(input())
arr = list(map(int,input().split(' ')))

k = arr.index(max(arr))
k+=1
ok = True

for i in range(1,k-1):
	ok &= arr[i-1]<arr[i]
for i in range(k,n-1):
	ok &= arr[i+1]<arr[i]
if ok :
	print('YES')
else:
	print('NO')
