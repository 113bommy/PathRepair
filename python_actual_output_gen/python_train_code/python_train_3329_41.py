n = int(input())
s = input()
c = 0
for i in range(2,n+1):
	if s[i-1:i] == 'SF':
		c +=1
	elif s[i-1:i] == 'FS':
		c -=1
if c > 0:
	print('YES')
else:
	print('NO')