N = int(input())
T = list(map(int, input().split()))
A = list(map(int, input().split()))

tmax = T[-1]
amax = A[0]
tf = T.index(tmax)
af = N - (list(reversed(A))).index(amax) - 1

if tf > af or tmax != amax:
	print(0)

else:
	ans = 1
	for i in range(1, tf + 1):
		if T[i] == T[i - 1]:
			ans = (ans * T[i - 1]) % 1000000007

	for i in range(af - tf - 1):
		ans = (ans * tmax) % 1000000007
	for i in range(af + 1, N):
		if A[i] == A[i - 1]:
			ans = (ans * A[i - 1]) % 1000000007

	print(ans)