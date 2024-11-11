n = int(input())
A = list(map(int, input().split()))

cnt = 0
for i in range(n):
	cnt += (A[i] == i)

if cnt == n:
	print(n)
else:
	ind = False
	for i in range(n):
		ind &= (A[i] != i and A[A[i]] == i)
	if ind:
	    print(cnt + 2)
	else:
		print(cnt + 1)