n = int(input())
s = input()
c = 0
for i in range(2,n+2):
	if s[i-2:i] == 'SF':
		c +=1
	elif s[i-2:i] == 'FS':
		c -=1
if c > 0:
	print('YES')
else:
	print('NO')