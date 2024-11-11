s=input().strip(" ")
s=s.strip('{')
s=s.strip('}')
s=s.split(",")
c=0
l=[]
if s!=['']:
	for letter in s:
		if letter in l:
			continue
		else:
			l = l+ [letter,]
print(len(l))