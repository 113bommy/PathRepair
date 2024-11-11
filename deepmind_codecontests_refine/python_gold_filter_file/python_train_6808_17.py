s =input()
arr = []
a = 0
while a <len(s):
	if s[a] ==".":
		arr.append(0)
		a+=1
	elif s[a]=="-":
		if s[a+1] =="-":
			arr.append(2)
			a+=2
		else:
			arr.append(1)
			a+=2
print("".join(map(str,arr)))

