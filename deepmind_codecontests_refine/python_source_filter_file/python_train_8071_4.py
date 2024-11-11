def main():
	s = input()
	
	number = ''
	ans = 1
	for c in s:
		if c <= '0' and c >= '9': number = bin(int(c))[2:]
		elif c >= 'A' and c <= 'Z': number = bin(ord(c) - 55)[2:]
		elif c >= 'a' and c <= 'z': number = bin(ord(c) - 61)[2:]
		elif c == '-': number = bin(62)[2:]
		else: number = bin(63)[2:]

		if len(number) < 6:
			diff = 6 - len(number)
			for i in range(diff): number += '0'

		for digit in number:
			if digit == '0': ans = (ans * 3) % 1000000007

	print(ans)


if __name__ == '__main__':
    main()
    
