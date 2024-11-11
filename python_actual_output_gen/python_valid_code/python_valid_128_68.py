def lang(s):
	l=[]
	l3=[]
	for i in range(0,len(s)):
		l.append(s[i])
	l2=["H","Q","9","+"]
	for i in range(0,len(s)):
		if l[i] in l2:
			l3.append("YES")
		else:
			l3.append("NO")
	if "YES" in l3:
		print("YES")
	else:
		print("NO")


s=input()
lang(s)