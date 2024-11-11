import sys

match = input().lower()

s = str()
for line in sys.stdin:
	s += line.lower()
print(s.split().count(match))