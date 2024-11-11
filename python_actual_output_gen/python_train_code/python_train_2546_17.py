D,G = map(int,input().split())
X = [list(map(int,input().split())) for _ in range(D)]
ans = 0
 
for i in range(2**D):
	point = 0
	count = 0
	for j in range(D):
		if (i>>j)&1:
			point += 100*(j+1)*X[j][0]+X[j][1]
			count += X[j][0]
	if 	G > point:
		for k in range(D)[::-1]:
			if (i>>k)&1==0:
				if (G-point) <= 100*(k+1)*(X[k][0]-1):
					count +=  ((G-point) // (100*(k+1)))
					break
				else:
					count = 10**5
					break
	if ans == 0 or count < ans:
		ans = count
 
print(ans)