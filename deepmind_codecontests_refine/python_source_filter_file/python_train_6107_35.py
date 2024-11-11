tapyldy = False
k = 0
m = 0
n = input()
for i in n:
	if i == '0':
		k+=1
		if k >= 7:
			tapyldy = True
			break
	else:
		k = 0
	
	if i == '1':
		m+=1
		if m >= 7:
			tapyldy = True
			break
	else:
		m = 0
if tapyldy == True:
	print("yes") 
else:
	print('no')