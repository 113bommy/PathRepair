'''input
11
'''

def precomputation():
	arr = [0] * (10 ** 6 + 1)
	arr[4] = 1
	arr[7] = 1
	for i in range(4, 10 ** 6 -7):
		if arr[i] == 1:
			arr[i + 4] = 1
			arr[i + 7] = 1
	return arr

def find_num(n):
	four = 0
	seven = 0
	while n > 0:
		if n % 7 == 0:
			q = n // 7
			seven += q
			n = n - q * (7)
		elif n % 4 == 0:
			q = n // 4
			four += q
			n = n - q * (4)
		
		else:
			n = n - 7
			seven += 1

	seven += 4 * (four // 7)
	four = four % 7
	
	return ('4' * four + '7' * seven)

arr = precomputation() 
n = int(input())
if arr[n] == 1:
	print(find_num(n))
else:
	print(-1)
