number = input()

def lucky(num):
		for digit in num:
			if int(digit) != 4 and int(digit) != 7:
				num = num.replace(digit , "")
		length = len(num)
		for digit in str(length):
			if int(digit) != 4 and int(digit) != 7:
				return 0
		return 1


def main():
	if lucky(number):
		print ("YES")
	else:
		print ("NO")

if  __name__ == "__main__":
	main()
