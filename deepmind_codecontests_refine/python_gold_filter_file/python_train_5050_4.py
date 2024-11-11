s = input()

count = [0] * 26

for i in s:
	count[ord(i)-ord('a')] += 1

ind = []

for i in range(26):
	if count[i] % 2:
		ind.append(i)

i = 0
j = len(ind) - 1
while j-i > 0:
	count[ind[i]] += 1
	count[ind[j]] -= 1
	i += 1
	j -= 1

# print(count)

s = ""

j = -1
for i in range(26):
	if count[i] % 2:
		j = i	
	s += chr(i+97) * (count[i] // 2)

ss = s[::-1]
if j != -1:
	s += chr(j+97)

s += ss
print(s)
