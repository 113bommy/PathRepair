t=int(input())
for i in range(t):
	n=int(input())
	b=input()
	s="1"
	for j in range(1,len(b)):
		if b[j]=="0" and b[j-1]=="1":
			if s[len(s)-1]=="0":
				s+="0"
			else:
				s+="1"
		elif b[j]=="1" and b[j-1]=="0":
			if s[len(s)-1]=="0":
				s+="1"
			else:
				s+="1"
		elif b[j]=="0" and b[j-1]=="0":
			if s[len(s)-1]=="0":
				s+="1"
			else:
				s+="0"
		elif b[j]=="1" and b[j-1]=="1":
			if s[len(s)-1]=="0":
				s+="1"
			else:
				s+="0"
	print(s)