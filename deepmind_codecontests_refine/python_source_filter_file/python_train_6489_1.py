def getscore(a,b,c):
	# print(a,b,c)
	if ((len(a)>1 and a[0]=='0') or (len(b)>1 and b[0]=='0') or(len(c)>1 and c[0]=='0')):
		# print('Leading 0')
		return -1
	if(int(a)>1000000 or int(b)>1000000 or int(c)>1000000):
		# print('greater than 1000000')
		return -1
	else:
		return int(a)+int(b)+int(c)
	
s=input()
maxsc=-2
for i in range(1,len(s)-1):
	for j in range(i+1,len(s)):
		a=s[:i]
		b=s[i:j]
		c=s[j:]
		score=getscore(a,b,c)
		if score>maxsc:
			maxsc=score

print(maxsc)


