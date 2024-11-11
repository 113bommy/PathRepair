

x=list("qwertyuiop")
b=list("asdfghjkl;")
c=list("zxcvbnm,./")

n=input()
if(n=="R"):
	a=-1
else:
	a=1
s=list(input())

for i in range(len(s)):
	if(a==1 and (s[i]==x[-1] or s[i]==b[-1] or s[i]==c[-1])):
		continue
	elif(a==-1 and (s[i]==x[0] or s[i]==b[0] or s[i]==c[1])):
		continue
	if(s[i] in x):
		s[i]=x[x.index(s[i])+a]
	elif(s[i] in b):
		s[i]=b[b.index(s[i])+a]
	elif(s[i] in c):
		s[i]=c[c.index(s[i])+a]
print("".join(s))
