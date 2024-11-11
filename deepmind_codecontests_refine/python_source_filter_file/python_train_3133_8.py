s = input()
t = input()	

i = len(s)
j = len(t)

while i >= 0 and j >= 0:
	if s[i-1] != t[j-1]:
		break
	i -= 1
	j -= 1

print(i + j)