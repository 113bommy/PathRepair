n,m = map(int,input().split())
a = []
b = []
for i in range(n):
	temp = list(map(int,input().split()))
	a.append(temp)
for i in range(n):
	temp = list(map(int,input().split()))
	b.append(temp)


for i in range(n-1):
	for j in range(m-1):

		t1 = [a[i][j],b[i][j]]	
		t2 = [a[i+1][j],b[i+1][j]]
		t3 = [a[i][j+1],b[i][j+1]]

		t1.sort()
		t2.sort()
		t3.sort()

		if t2[0] <= t1[0] or t3[0] <= t1[0] or t2[1] <= t1[1] or t3[1] <= t1[0]:
			print("Impossible")
			exit(0)

for i in range(m-1):
	t1 = [a[n-1][i],b[n-1][i]]
	t2 = [a[n-1][i+1],b[n-1][i+1]]

	t1.sort()
	t2.sort()

	if t2[0] <= t1[0] or t2[1] <= t1[1]:
		print("Impossible")
		exit(0)


for i in range(n-1):
	t1 = [a[i][m-1],b[i][m-1]]
	t2 = [a[i+1][m-1],b[i+1][m-1]]

	t1.sort()
	t2.sort()

	if t2[0] <= t1[0] or t2[1] <= t1[1]:
		print("Impossible")
		exit(0)

print("Possible")