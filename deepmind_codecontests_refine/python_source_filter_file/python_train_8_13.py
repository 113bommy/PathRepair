n = int(input())
s = input()
output = 0

if s.count('8')>0:
	num = 11*s.count('8')
	if num <= n:
		output = n//num
	else:
		output = n//11

print(output)


