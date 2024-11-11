#!/usr/local/bin/python3

import sys

n = int(sys.stdin.readline())

zero_result = 0
ones_result = 1023

while (n > 0) :
	[op, val] = sys.stdin.readline().split(" ")
	val = int(val)
	n -= 1
	if (op == '&') :
		zero_result = zero_result & val
		ones_result = ones_result & val
	elif (op == '|') :
		zero_result = zero_result | val
		ones_result = ones_result | val
	elif (op == '^') :
		zero_result = zero_result ^ val
		ones_result = ones_result ^ val
	else:
		pass

and_bin = [1 for i in range(10)]
or_bin = [0 for i in range(10)]
xor_bin = [0 for i in range(10)]

for i in range(10) :
	j = 9 - i 
	zero_digit = zero_result >> j 
	ones_digit = ones_result >> j
	zero_result = zero_result - zero_digit*(2**j)
	ones_result = ones_result - ones_digit*(2**j)
	if ((zero_digit == 0) and (ones_digit == 0)) :
		and_bin[i] = 0
	elif ((zero_digit == 1) and (ones_digit == 0)) :
		xor_bin[1] = 1
	elif ((zero_digit == 1) and (ones_digit == 1)) :
		or_bin[i] = 1

and_int = 0
xor_int = 0
or_int = 0

for i in range(10):
	and_int += and_bin[i]*(2**i)
	or_int += or_bin[i]*(2**i)
	xor_int += xor_bin[i]*(2**i)

print(3)
print('&', and_int)
print('|', or_int)
print('^', xor_int)


