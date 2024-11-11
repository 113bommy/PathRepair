import sys
L = sys.stdin.readlines()
for line in L:
	N = line.split()
	sums = int(N[0]) + int(N[1])
	print(len(str(sums))+1)