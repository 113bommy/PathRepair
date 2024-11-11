a=True
p = input()
counter = 0
for i in p:
	if i =='1':
		if a:
			counter +=1
		else:
			counter = 1
			a=True
	else:
		if not a:
			counter +=1
		else:
			counter = 1
			a = False
	if counter == 7:
#		print("YES")
		break
if counter == 7:
	print("YES")
else:
    print("NO")