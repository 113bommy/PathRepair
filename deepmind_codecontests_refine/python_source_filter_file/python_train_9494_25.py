import math

T = int(input())

while T > 0:
	# R, P, S
	n = int(input())
	a, b, c = map(int, input().split())
	seq = input()
	aliceWins = 0
	bobWins = 0
	winCombo = ''
	for ch in seq:
		if ch == 'R':
			if b > 0:
				winCombo += 'P'
				b -= 1
				aliceWins += 1
			else:
				bobWins += 1
				winCombo += 'x' # Fill these positions later
		elif ch == 'P':
			if a > 0:
				winCombo += 'S'
				a -= 1
				aliceWins += 1
			else:
				bobWins += 1
				winCombo += 'x'
		else:
			if c > 0:
				winCombo += 'R'
				c -= 1
				aliceWins += 1
			else:
				bobWins += 1
				winCombo += 'x'
	winCombo = list(winCombo)
	for i in range(len(winCombo)):
		if winCombo[i] == 'x':
			if a > 0:
				winCombo[i] = 'R'
				a -= 1
			elif b > 0:
				winCombo[i] = 'P'
				b -= 1
			else:
				winCombo[i] = 'S'
				c -= 1
	winCombo = ''.join(winCombo)
	if aliceWins >= math.ceil(n/2):
		print("YES")
		print(winCombo)
	else:
		print("NO")
	T -= 1