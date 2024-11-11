n = int(input())
a = int(input())
b = int(input())
c = int(input())

s = 0
n -= 1
output = 0
while n:
	if s == 0:
		if a < b:
			output += a
			s = 1
		else:
			output += b
			s = 2
	elif s == 1:
		if a < c:
			output += a
			s = 0
		else:
			output += c
			s = 2
	else:
		if b < c:
			output += b
			s = 0
		else:
			output += c
			s = 1
	n -= 1

print(output)