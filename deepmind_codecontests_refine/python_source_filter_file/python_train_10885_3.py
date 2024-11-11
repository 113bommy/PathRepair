s = input()
n = []
p = []
for i in range(1,len(s)):
	if s[i] == ".":
		if i+3 >= len(s):
			p[-1]+=str(s[i])
		else:
			if s[i+3].isalpha():
				p[-1]+=str(s[i])
	if s[i].isdigit():
		if s[i-1].isdigit() or s[i-1] == ".":
			if len(p) > 0:
				p[-1]+=str(s[i])
			else:
				p.append(str(s[i]))
		else:
			p.append(s[i])
s = 0
for a in p:
	s+=float(a)
if int(s) == s:
	s = '{:,}'.format(s).replace(",",".")
else:
	s = '{:,.2f}'.format(s).replace(",",".")
print(s)
