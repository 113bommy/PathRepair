a = "AHIMNOUYTXWV" 
b = True
c = input()
for x in c:
	if x not in a:
		b = False
		break
else:
	if c[::-1] != c:
		b = False
if b == True:
	print("YES")
else:
	print("NO")