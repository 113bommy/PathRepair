
def main():
	import sys
	def get_multiple_ints():
		return list(map(int, sys.stdin.readline().strip().split()))

	def get_single_int():
		return list(map(int,sys.stdin.readline().strip()))[0]

	for _ in range(get_single_int()):

		length = get_single_int()
		passwords = get_multiple_ints()
		passwords.sort()
		if passwords[0] == passwords[-1]:
			print(length)
		else:
			print(1)


if __name__ == '__main__':
	main()