n, d = map(int,input().split())
arr = [int(x) for x in input().split()]
i,j,c = 0,2,0
if n < 3:
	print(0)
else:
	while True:
		if i>n-3 and j>=n-1:
			break
		elif arr[j]-arr[i]<=d and j<n-1:
			j+=1
		elif j==n-1 and arr[j]-arr[i]<=d:
			z = j-i
			c += (z*(z-1))//2
			i += 1
		else:
			z = j-i-1
			c += (z*(z-1))//2
			i += 1
print(c)