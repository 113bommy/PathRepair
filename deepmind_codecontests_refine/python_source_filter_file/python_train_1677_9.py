s=input()
c=[0]
n=len(s)
for i in range(1,n-1):
	if s[i+1]==s[0]:
		c.append(1)
		s=s[:i+1][::-1]+s[i+1:]

	else:
		c.append(0)
		
if n==1:
	print(0)

elif n==2:
	if s=="aa" or s=="bb" or s=="ab":
		print(0,0)

	elif s=="ba":
		print(0,1)

else:
	if s[-1]=="a":
		c.append(1)

	else:
		c.append(0)

print(*c)


