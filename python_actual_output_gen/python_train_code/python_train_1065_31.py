# your code goes here
w = {'q':9,'r':5,'b':3,'n':3,'p':5,'k':0,'.':0}
white = 0
black = 0
for k in range(8):
	i = input()
	for j in i:
		if j in w:
			white = white + w[j]
		else:
			black = black + w[chr(ord(j)+32)]

if white < black:
	print('White')
elif black < white:
	print('Black')
else:
	print('Draw')