n, m = map(int, input().split())
a = [int(x) for x in input().split()]

if n > m or a[0]==0:
	print("YES")
	exit(0)

can = []
for i in range(n):
	can.append([0] * m)

can[0][0] = 1
can[0][a[0]%m] = 1


for i in range(n-1):
	for j in range(m):
		if can[i][j] > 0:
			r = (j+a[i+1])%m
			if r==0 or a[i+1]==0:
				print("YES")
				exit(0)
			can[i+1][r] = 1
			can[i+1][j] = 1

print("NO")
