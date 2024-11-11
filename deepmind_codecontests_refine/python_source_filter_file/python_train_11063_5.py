T = int(input())

for _ in range(T):
	N = int(input())
	A = list(map(int,input().split()))
	ct1 = sum(A)
	ct0 = N - ct1

	rem = 0

	if ct1 <= N//2:
		print(ct0)
		print(*[0]*ct1,sep=' ')
	else:
		rem = ct1 - ct1%2
		print(rem)
		print(*[1]*rem,sep=' ')



