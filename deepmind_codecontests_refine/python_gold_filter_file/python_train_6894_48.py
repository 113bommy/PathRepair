t = int(input())

result = str()

for i in range(t):
	n, m = list(map(int, input().split()))
	if not(n % m):
		result += '\nYES'
	else:
		result += '\nNO'

result = result.strip()
print(result)
