# import sys
# sys.stdin = open("#input.txt", "r")

d = {
	'Q': 9,
	'R': 5,
	'B': 3,
	'N': 3,
	'P': 3
}

w = b = 0
for _ in range(8):
	for c in input():
		if c in d:
			w += d[c]
		else:
			t = str(chr(ord(c)-32))
			if t in d: b += d[t]

print(["Black","White"][w>b] if w!=b else "Draw")