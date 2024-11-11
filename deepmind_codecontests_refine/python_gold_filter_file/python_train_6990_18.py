import sys

if __name__ == '__main__':
	n, m = list(map(int,input().split()))
	table = []
	xor_test = 0
	for _ in range(n):
		temp = list(map(int,input().split()))
		table.append(temp)
		xor_test ^= temp[0]
	if xor_test != 0:
		print('TAK')
		for _ in range(len(table)): print(1,end=' ')
		sys.exit()
	result_r = -1
	result_c = -1
	for i in range(len(table)):
		test = table[i][0]
		for j in range(1,len(table[i])):
			if table[i][j] != test:
				result_r = i
				result_c = j
				break
		if result_c != -1:
			break
	if result_c == -1:
		print('NIE')
		sys.exit()
	print('TAK')
	for _ in range(result_r): print(1,end=' ')
	print(result_c + 1,end=' ')
	for _ in range(result_r + 1,len(table)): print(1,end=' ')