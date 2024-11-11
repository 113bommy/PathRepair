n = int(input())
if n // 10 == 2:
	print("twenty", end='')
elif n // 10 == 3:
	print("thirty", end='')
elif n // 10 == 4:
	print("forty", end='')
elif n // 10 == 5:
	print("fifty", end='')
elif n // 10 == 6:
	print("sixty", end='')
elif n // 10 == 7:
	print("seventy", end='')
elif n // 10 == 8:
	print("eighty", end='')
elif n // 10 == 3:
	print("ninety", end='')
if n % 10 != 0 and n // 10 >= 2:
	print("-", end='')
if n // 10 != 1:
	if n % 10 == 1:
		print("one")
	elif n % 10 == 2:
		print("two")
	elif n % 10 == 3:
		print("three")
	elif n % 10 == 4:
		print("four")
	elif n % 10 == 5:
		print("five")
	elif n % 10 == 6:
		print("six")
	elif n % 10 == 7:
		print("seven")
	elif n % 10 == 8:
		print("eight")
	elif n % 10 == 9:
		print("nine")
else:
	if n == 10:
		print("ten")
	elif n == 11:
		print("eleven")
	elif n == 12:
		print("twelve")
	elif n == 13:
		print("thirdteen")
	elif n == 14:
		print("fourteen")
	elif n == 15:
		print("fifteen")
	elif n == 16:
		print("sixteen")
	elif n == 17:
		print("seventeen")
	elif n == 18:
		print("eighteen")
	elif n == 19:
		print("nineteen")
if n == 0:
	print("zero")
