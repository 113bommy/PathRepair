#import sys
#sys.stdin = open("123.data")
def check(s):
	alp = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
	alp1 = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
	c = [0 for i in range(26)]
	for i in range(26):
		if s[i] != '?':
			c[alp.index(s[i])] += 1
			if int(c[alp.index(s[i])]) > 1:
				return ''
			elif s[i] in alp1:
				alp1.remove(s[i])
	ans = ''
	uk = 0
	for i in range(26):
		if s[i] == '?':
			ans += alp1[uk]
			uk += 1
		else:
			ans += s[i]
	return ans
s = input()
n = len(s)
if n < 26:
	print(-1)
fl = False
tmp = ''
for i in range(n - 25):
	tmp = check(s[i:i + 26])
	if tmp != '':
		for j in range(n):
			if j < i or j >= i + 26:
				if s[j] == '?':
					print('A', end = '')
				else:
					print(s[j], end = '')
			else:
				print(tmp[j - i], end = '')
		exit()
		fl = True
if not(fl):
	print(-1)

