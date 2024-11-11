s1 = input()
s2 = [int(s1[x]) for x in range(0, len(s1), 2)]
s2.sort()
s = ""
for x in s2:
	s += str(s2)
	s += "+"
print(s[0:len(s)-1])