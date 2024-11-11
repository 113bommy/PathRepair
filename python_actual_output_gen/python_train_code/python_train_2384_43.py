t = int(input())

result = str()

for i in range(t):
	n, m = list(map(int, input().split()))
	if m * 2 == n:
		result += '\nYES'
	else:
		result += '\nNO'

result = result.strip()
print(result)
