n = int(input())
string = input()

freq = [0] * 26
for i in string:
	freq[ord(i) - ord('a')] += 1

free = 0
repeated = 0
for i in range(len(freq)):
	if (freq[i] == 0):
		free += 1
	elif (freq[i] > 1):
		repeated += freq[i] - 1

if (free > repeated):
	print(repeated)
else:
	print(-1)

