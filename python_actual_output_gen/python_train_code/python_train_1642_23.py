s=[n for n in input()]
for n in range(len(s)):
	if ord('z')>=ord(s[n])>=ord('a'):
		s[n]=chr(ord(s[n])-32)
k=[]
print(s)
for n in s:
	if ord('Z')>=ord(n)>=ord('A'):
		k.append(n)
print(k)
v=['A','E','I','O','U','Y']
if k[len(k)-1] in v:
	print('YES')
else:
	print('NO')