a, b, c = map(int, input().split())
div = 0

for n in range(a, b+1):
	if c % n == 0:
		div += 1
		
print(div)