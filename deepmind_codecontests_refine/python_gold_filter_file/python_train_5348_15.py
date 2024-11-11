"""
    author - Sayan Bose
    date - 29.01.2020
    Brooklyn 99 is love!
"""

s = input()
t = 'NO'
for i in range(len(s)):
	if s[i] == '0':
		t = i
		break
if t != 'NO':
	print(s[:t] + s[t+1:])
else:
	print(s[:-1])