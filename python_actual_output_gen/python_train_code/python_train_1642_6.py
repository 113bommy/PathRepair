s = input()
c = len(s)-1
fr1 = c

for fr1 in range(c,0,-1):
	if (s[fr1].upper()=='A' or s[fr1].upper()=='E' or s[fr1].upper()=='I' or s[fr1].upper()=='O' or s[fr1].upper()=='U'or s[fr1].upper()=='Y'):
		print("YES")
		exit()
	elif (s[fr1].isalpha()):
		print("NO")
		exit()