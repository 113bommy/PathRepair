def calculate(a, b):
	operations = 0
	while a != 0 and b != 0:
		if a == b:
			b -= 1
			operations += 1
		else:
			times = None
			if a > b:
				difference =  a - b
				times = int(difference / b)
				if difference % b != 0 and b * (times + 1) <= a:
					times += 1
				a -= (b * times)
			else:
				difference = b - a
				times = int(difference / a)
				if difference % a != 0 and a * (times + 1) <= b:
					times += 1
				b -= (a * times)
			operations += times
	return operations

def main():
	num_tests = int(input())
	for test in range(num_tests):
		a, b = input().strip().split(' ')
		a, b = int(a), int(b)
		print(str(calculate(a, b)))

main()