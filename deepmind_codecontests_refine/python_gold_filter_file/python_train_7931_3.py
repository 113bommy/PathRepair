def solve():
	n = int(input())

	numeros = list(map(int, input().split()))
	numeros.sort()
	for i in range(0,len(numeros)-1):
		if numeros[i+1] - numeros[i] <= 1:
			return 2
	return 1




a = int(input())

for i in range(0,a):
	print(solve())