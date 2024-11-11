x=int(input())
s=[ord(n) for n in input()]
p=0
if min(s)==max(s):
	del s[0]
else:
	for n in range(x-1):
		if s[n]>s[n+1]:
			del s[n]
			p=1
			break
	if p==0:
		del s[x-1]
	for n in s:
		print(chr(n),end='')