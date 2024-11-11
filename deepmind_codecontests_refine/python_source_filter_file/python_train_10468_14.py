s= input()
a = int(s[1])
l = 'abcdefgh'
b = l.find(s[1])+1
if (a == 1 or a == 8) and (b == 1 or b == 8):
	print(3)
elif a == 1 or a == 8:
	print(5)
elif b == 1 or b == 8:
	print(5)
else:
	print(8)
