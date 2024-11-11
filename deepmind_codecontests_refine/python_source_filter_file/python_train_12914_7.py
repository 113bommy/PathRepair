import sys
s = sys.stdin.read().lower()
for i in range (ord('a'), ord('z')+1):
	print(str(chr(i)), str(s.count(chr(i))), sep=':')