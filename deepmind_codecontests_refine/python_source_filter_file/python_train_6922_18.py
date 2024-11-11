nA, nB = map(int, input().split())
k, m = map(int, input().split())

lstA = list(map(int, input().split()))
lstB = list(map(int, input().split()))

chosenA = []
chosenB = []
for i in range(k):
	chosenA.append(lstA[i])

for i in range(-1, -m - 1, -1):
	chosenB.append(lstB[i])
ans = 'NO'
if chosenA[-1] < chosenB[0]:
	ans = 'YES'
print(ans)