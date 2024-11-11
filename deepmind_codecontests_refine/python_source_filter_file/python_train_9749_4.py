import sys
# For getting input from input.txt file
#sys.stdin = open('input.txt', 'r')

# Printing the Output to output.txt file
#sys.stdout = open('output.txt', 'w')

def gcd(a, b): 
	while a != 0 and b != 0:
		if a > b:
			a = a % b 
		else:
			b = b % a 

	return max(a, b)

n = int(input())

s = input()
num = list(map(int, s.split(' ')))

num.sort()

slen = []

for i in range(1, n):
	slen.append(num[i] - num[i - 1])

slen.sort()
minlen = slen[0]
maxlen = slen[-1]

for i in range(0, n - 1):
	if minlen == 1:
		break
	elif slen[i] % minlen != 0:
		minlen = gcd(minlen, slen[i])

print((num[-1] - num[0]) / minlen - n + 1)


