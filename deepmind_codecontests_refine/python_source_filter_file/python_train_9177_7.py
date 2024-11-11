N = int(input())
l = list(map(int, input().split()))
ansL = []
smallest = 10000000
ind = 0
if(N % 2 == 0):
	for i in range(N):
		if(l[i] < 0):
			ansL.append(l[i])
		else:
			neg = ((-1) * l[i] - 1)
			ansL.append(neg)
else:
	for i in range(N):
		if(l[i] < 0):
			ansL.append(l[i])
		else:
			neg = ((-1) * l[i] - 1)
			ansL.append(neg)
			
		if(abs(ansL[i]) < smallest):
			smallest = abs(ansL[i])
			ind = i

	ansL[ind] = ((-1) * ansL[ind] - 1)

for i in range(N):
	print(ansL[i], end= ' ')
