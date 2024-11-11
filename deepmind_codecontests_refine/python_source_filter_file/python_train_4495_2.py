b=list(input())
d=['a','o','y','e','u','i']
c=[]
for i in range(len(b)):
	if b[i]  in d or b[i].lower() in d:
		continue
	else:
		c.append('.')
		c.append(b[i])

c=''.join(c)
print(c)