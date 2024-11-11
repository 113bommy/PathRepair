N = int(input())
A = list(map(int, input().split()))
odd = 0
four = 0
for i in range(0, N):
	if A[i] % 4 == 0: four += 1
	if A[i] % 2 != 0: odd += 1
if odd <= four+1: print('Yes')
else: print('No')