def solve():
	a = input()
	b = input()
	j = 0

	for i in a:
		if i == b[j]:
			j += 1
		if j == len(b):
			break

	if j == len(b):
		return 'automation'
	 
	num = [0]*42
	for i in a:
		num[ord(i)-ord('a')] += 1
	for i in b:
		num[ord(i)-ord('a')] -= 1

	for i in num:
		if i < 0:
			return 'need tree'
	if sum(num) > 0:
		return 'both'
	else:
		return 'array'

if __name__ == '__main__':
	print(solve())
