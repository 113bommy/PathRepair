n = int(input())
i,j=0,1
mat = [0]
while j <= n:
	i,j = j,j+i
	mat.append(i)
res = []
k = len(mat)-1
while k > -1:

	if n-mat[k]>=0:
		res.append(mat[k])
		n-=mat[k]
		if len(res) >= 3:
			break
	else:
		k-=1
	if n<0:
		break

if n==0 and len(res)==3:
	print(*res)
else:
	print("I'm too stupid to solve this problem")