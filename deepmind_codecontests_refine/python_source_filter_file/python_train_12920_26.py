def is_big(char):
	return ord(char) >= 65 and ord(char) <= 90

def is_small(char):
	return ord(char) >= 97 and ord(char) <= 122

def is_num(char):
	return ord(char) >= 48 and ord(char) <= 57

def replace(string, i, char):
	s = list(string)

	s[i] = char

	return ''.join(s)

def alter(word, a, b, c):		# a - bigs, b - smls, c - nums
	if a == 0 and b == 0:
		word = replace(word, 0, 'A')
		word = replace(word, 1, 'a')

	elif b == 0 and c == 0:
		word = replace(word, 0, 'a')
		word = replace(word, 1, '0')

	elif a == 0 and c == 0:
		word = replace(word, 0, 'A')
		word = replace(word, 1, '0')

	elif a == 0 and b == 1 and c == 2:
		j = -1

		for i in range(len(word)):
			if is_num(word[i]):
				j = i
				break

		word = replace(word, j, 'A')

	elif a == 1 and b == 0 and c == 2:
		j = -1

		for i in range(len(word)):
			if is_num(word[i]):
				j = i
				break

		word = replace(word, j, 'a')

	elif a == 2 and b == 0 and c == 1:
		j = -1

		for i in range(len(word)):
			if is_big(word[i]):
				j = i
				break

		word = replace(word, j, 'a')


	elif a == 2 and b == 1 and c == 0:
		j = -1

		for i in range(len(word)):
			if is_big(word[i]):
				j = i
				break

		word = replace(word, j, '0')

	elif a == 1 and b == 2 and c == 0:
		j = -1

		for i in range(len(word)):
			if is_small(word[i]):
				j = i
				break

		word = replace(word, j, '0')

	elif a == 0 and b == 2 and c == 1:
		j = -1

		for i in range(len(word)):
			if is_small(word[i]):
				j = i
				break

		word = replace(word, j, 'A')

	elif a == 0:
		j = -1

		for i in range(len(word)):
			if is_num(word[i]) or is_small(word[i]):
				j = i
				break

		word = replace(word, j, 'A')

	elif b == 0:
		j = -1

		for i in range(len(word)):
			if is_num(word[i]) or is_big(word[i]):
				j = i
				break

		word = replace(word, j, 'a')

	elif c == 0:
		j = -1

		for i in range(len(word)):
			if is_big(word[i]) or is_small(word[i]):
				j = i
				break

		word = replace(word, j, '0')

	return word

def wrap(word):
	nums = 0
	bigs = 0
	smls = 0

	for ch in word:
		if is_big(ch):
			bigs += 1

		elif is_small(ch):
			smls += 1

		elif is_num(ch):
			nums += 1

	if bigs > 0 and smls > 0 and nums > 0:
		return word

	if nums > 1:
		nums = 2

	if bigs > 1:
		bigs = 2

	if smls > 1:
		smls = 2

	print(bigs, smls, nums)

	return alter(word, bigs, smls, nums)


def main():
	n = int(input())

	ress = []

	for i in range(n):
		word = input()

		res = wrap(word)

		ress.append(res)

	for res in ress:
		print(res)

if __name__ == '__main__':
	main()