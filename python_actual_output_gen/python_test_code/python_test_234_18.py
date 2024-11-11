n=input()
i=0
j=0
while j<len(n):
	if n[i:i+3]=="144":
		j+=3
	elif n[i:i+2]=="14":
		j+=2
	elif n[i:i+1]=="1":
		j+=1
	else:
		i=5
		break
print(["YES","NO"][i==5])
