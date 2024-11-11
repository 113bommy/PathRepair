def read_int():
	return int(input().strip())

def read_string():
	return input().strip()

def read_int_list():
	return list(map(int,input().strip().split()))

def read_string_list():
	return input().strip().split()

import sys, math

#### Write code from here ####
q = read_int()

pows = set()

for i in range(1,26):
	pows.add(2**i - 1)

for i in range(q):
	n = read_int()
	if n in pows:
		out = 1
		for i in range(2,math.ceil(math.sqrt(n))):
			if n%i == 0:
				out = n//i
		print(out)
	else:
		print(2**(int(math.log2(n))+1) - 1)
