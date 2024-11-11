w=input()
num=0
while True:
	t=input()
	if t=='END_OF_TEXT':
		break
	else:
		s=t.split()
		for i in s:
			if i==w:
				num+=1
print(num)
