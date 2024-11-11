firstname, lastname = input().split()
a = firstname[0]
for i in range(1,len(firstname)):
	if ord(firstname[i])<ord(lastname[0]):
		a += firstname[i]
	else:
		break
print(a+lastname[0])		