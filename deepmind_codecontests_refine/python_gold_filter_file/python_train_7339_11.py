from sys import stdin
live = True
if not live: stdin = open('data.in', 'r')

closeA = closeB = 7
lines = [''] * 8

for it in range(1, 9):
	lines[it - 1] = list(stdin.readline().strip())

for it in range(0, 8):
	for jt in range(0, 8):
		if lines[it][jt] == 'W' and it < closeA:
			save = True
			for iit in range(0, it):
				if lines[iit][jt] != '.': save = False
			if save: closeA = it
		if lines[it][jt] == 'B' and (7 - it) < closeB:
			save = True
			for iit in range(it + 1, 8):
				if lines[iit][jt] != '.': save = False
			if save: closeB = 7 - it

if closeA <= closeB:
	print('A')
else: print('B')
			
if not live: stdin.close()