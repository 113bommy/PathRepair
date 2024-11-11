n = int(input())
s = input()
output = 0

if s.count('8')>0:
	num = s.count('8')
	if num*11 <= n:
		output = num
	else:
		output = n//11

print(output)


