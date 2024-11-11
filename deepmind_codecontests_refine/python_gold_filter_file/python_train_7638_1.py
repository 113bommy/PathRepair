inp = list(map(int,input().split()))

row = inp[0]
col = inp[1]
d = inp[2]

mat = []

arr = []
for r in range(row):
	mat.append(list(map(int,input().split())))
	for c in range(col):
		arr.append(mat[r][c])

arr.sort()

if arr[0]==arr[-1]:
	print(0)

else:
	cant = False
	for i in range(1,len(arr)):
		if (arr[i]-arr[i-1])%d!=0:
			cant=True
			break

	if cant:
		print(-1)
	else:
		ans = 0
		target=arr[int(len(arr)/2)]
		for i in range(len(arr)):
			ans+=int(abs(target-arr[i])/d)
		print(ans)