'''input
4
(
((
(((
(())
'''
from sys import stdin


def calculate_score(bracket):
	score = dict()
	for element in bracket:
		count = 0
		for c in element:
			if c == '(':
				count += 1
			else:
				count -= 1
		score[element] = count
	return score


def is_positive(string):
	count = 0
	for c in string:
		if c == '(':
			count += 1
		else:
			count -= 1
		if count < 0:
			return False
	if count < 0:
		return False
	return True


def is_negative(string):
	count = 0
	for i in range(len(string) - 1, -1, -1):
		if string[i] == '(':
			count += 1
		else:
			count -= 1
		if count > 0:
			return False

	return True


# main starts
n = int(stdin.readline().strip())
opening = dict()
closing = dict()
bracket = []
for _ in range(n):
	bracket.append(stdin.readline().strip())

bracket = list(set(bracket))
score = calculate_score(bracket)

zero = 0
for element in bracket:
	if is_positive(element):
		if score[element] == 0:
			zero += 1
			continue
		else:
			try:
				opening[score[element]] += 1
			except:
				opening[score[element]] = 1
		continue
	elif is_negative(element):
		try:
			closing[score[element]] += 1
		except:
			closing[score[element]] = 1
		continue

count = zero // 2

for key in opening:
	if -key in closing:
		count += min(opening[key], closing[-key])
	
print(count)



