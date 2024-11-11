x = int(input())
myStr = input()

def func(myStr):
	choice = 0
	n = len(myStr)
	for i, c in enumerate(myStr):
		if c != '?':
			if i + 1 < n:
				if c == myStr[i + 1]:
					return False
					break
		elif c == '?' and choice < 2:
			if i + 1 < n:
				if c == myStr[i + 1]:
					choice += 2
				else:
					if i - 1 < 0 :
						choice += 2
					else:
						if myStr[i - 1] == myStr[i + 1]:
							choice += 2
						else:
							choice += 1
			else:
				choice += 2
		
	
	if choice >= 2:
		return True
	else:
		return False

z = func(myStr)
if z == True:
	print('Yes')
else:
	print('No')