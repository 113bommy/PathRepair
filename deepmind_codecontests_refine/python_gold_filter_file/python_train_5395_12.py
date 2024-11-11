n = int(input())
def cnt(x):
	return sum(1 for i in range(1, x+1) if x%i == 0)
print(sum(1 for i in range(1, n+1, 2) if cnt(i) == 8))