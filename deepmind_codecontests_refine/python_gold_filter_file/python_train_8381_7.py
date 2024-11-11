s = input()

a = s.count('0') + s.count('4') + s.count('8')

for i in range(len(s) - 1):
	if int(s[i:i + 2]) % 4 == 0:
		a += i + 1

print(a)
