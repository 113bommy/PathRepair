import sys



input       = []
input_index = 0

def next(type, number = None):
	def next():
		global input, input_index
		
		
		while input_index == len(input):
			if sys.stdin:
				input       = sys.stdin.readline().split()
				input_index = 0
			else:
				raise Exception()
				
				
		input_index += 1
		
		return input[input_index - 1]
		
		
	if number is None:
		result = type(next())
	else:
		result = [type(next()) for _ in range(number)]
		
	return result
	
	
	
n, k = next(int, 2)
bs = next(int, n)

oc = 0
for b in bs:
	oc += 1 if b % 2 == 1 else 0
ec = n - oc

dh = (n - k) // 2
sh = (n - k) - dh


if n == k:
	if oc % 2 == 0:
		print("Daenerys")
	else:
		print("Stannis")
else:
	if k % 2 == 0:
		if dh == sh:
			print("Daenerys")
		else:
			if dh >= oc or dh >= ec:
				print("Daenerys")
			else:
				print("Stannis")
	else:
		if dh == sh:
			if sh >= ec:
				print("Stannis")
			else:
				print("Daenerys")
		else:
			if dh >= oc:
				print("Daenerys")
			else:
				print("Stannis")
				