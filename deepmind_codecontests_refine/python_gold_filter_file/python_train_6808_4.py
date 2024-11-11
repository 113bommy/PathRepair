a=input()
b=[]
i=int(0)
while i<len(a):
	if a[i]==".":
		b.append("0")
		i+=1
	elif a[i]=="-":
		if a[i+1]==".":
			b.append("1")
			i+=2
		elif a[i+1]=="-":
			b.append("2")
			i+=2
print("".join(b))