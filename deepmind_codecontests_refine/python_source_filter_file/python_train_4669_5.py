N = int(input())

maxi = -1
sc = 0

for i in range(N):
	A, B = map(int, input().split())
	if A > mini:
		mini = A
		sc = B
print(mini + sc)
