'''input
4
>><<
'''
n = int(input())
s = input()
t = "<"
for x in range(n):
	if t != s[x]:
		break
else:
	x += 1
s = s[::-1]
t = ">"
for y in range(n):
	if t != s[x]:
		break
else:
	x += 1
print(x + y)



