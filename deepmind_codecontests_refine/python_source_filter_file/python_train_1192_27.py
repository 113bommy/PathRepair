a=input()
string=list(input())
keyboard1=list('qwertyuiopasdfghjkl;zxcvbnm,./')
orig=[]
if a=='l':
	for i in string:
		orig.append(keyboard1[keyboard1.index(i)+1])
	print(''.join(orig))
else:
	for i in string:
		orig.append(keyboard1[keyboard1.index(i)-1])
	print(''.join(orig))
