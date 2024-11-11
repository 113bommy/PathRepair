from math import sqrt

n = int(input())
inp = [int(x) for x in input().split()]

x = y = 0
freq = [0] * 10001
for i in inp :
	freq[i] += 1
	x = max(x, i)

fact = x
for i in range (1, int(sqrt(fact))) :
	if fact % i == 0 :
		div = fact // i
		if i == div :
			freq[i] -= 1
		else :
			freq[i] -= 1
			freq[div] -= 1

for i in range (1, 10001) :
	if freq[i] != 0 :
		y = max(y, i)

print(F"{x} {y}")