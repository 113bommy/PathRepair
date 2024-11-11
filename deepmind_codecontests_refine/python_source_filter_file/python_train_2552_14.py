def main():
	n = int(input())
	a = [int(x) for x in input().split()]
	print(solver(a))

def solver(L):
	L.sort(reverse = True)
	total = 0
	current = L[0] + 1
	for i in range(len(L)):
		if L[i] >= current:
			current -= 1
			if current <= 0:
				break
		else:
			current = L[i]
		total += current
	return total

#L1 = [2, 5, 5]
#print(solver(L1))

#L1 = [1, 1, 2, 2, 2]
#print(solver(L1))