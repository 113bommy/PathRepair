''' Author @isumit '''
def solve():
	N = int(input())
	A = list(map(int, input().split()))
	for i in range(N):
		if A[i] - A[i-1] > 1:
			print("NO")
			return
	print("YES")
	return

Testcase = 1
Testcase = int(input())
for _ in range(Testcase):
	solve()