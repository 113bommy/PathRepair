import math

permutation = [["R","G","B"],["R","B","G"],["G","B","R"],["G","R","B"],["B","G","R"],["B","R","G"]]
contadores = [0,0,0,0,0,0]

i = int(input())
melhor = i+1

menor = -1
s = input()
garden = list(s)

for a in range(0,6):
	str = permutation[a]
	for b in range(0,i):
		if garden[b] != permutation[a][b%3]:
			contadores[a]+=1

for a in range(0,6):
	if(contadores[a] <= melhor):
		melhor = contadores[a]
		menor = a

print(melhor)

for x in range(0,i):
	if garden[b] != permutation[menor][b%3]:
			garden[b] = permutation[menor][b%3]

s = ''.join(garden)	
print(s)




	


