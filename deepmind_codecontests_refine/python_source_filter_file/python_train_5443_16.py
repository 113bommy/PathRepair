if __name__ == '__main__':
	number_of_testcase = int(input())
	for testcase in range(number_of_testcase):
		key_input = input().strip().split(' ')
		l = int(key_input[0])
		r = int(key_input[1])
		if r%l > r-l:
			print('YES')
		else:
			print('NO')
