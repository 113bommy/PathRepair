a = input().split('>')
print(*a)
bal = 0
for s in a:
	if len(s) == 0:
		continue

	if (s[1] == '/'     ):
		bal -= 1
		print(bal * "  " + s+ ">")
	else:
		print(bal * "  " + s + ">")
		bal +=1
                     
       	