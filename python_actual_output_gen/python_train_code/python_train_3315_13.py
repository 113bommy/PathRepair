N = int(input())
A = list(map(int, input().split()))
numberlist = []
for i in range(0, N):
	numberlist.append([i+1, A[i]])
odd = []
even = []
for i in range(0, N):
	if numberlist[i][1]%2 == 0: even.append(numberlist[i])
	else: odd.append(numberlist[i])
if len(even) == 1: print(even[0][0])
else: odd[0][0]