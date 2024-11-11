# Main maut ko takiya, aur kafan ko chaadar banakar audhta hoon!

n=int(input())

s=input()


noof=0
while(s.find("__")!=-1):
	s=s.replace("__","_")

while(s.find("(")!=-1):
	start=s.find("(")
	end=s.find(")")
	
	l=s[start+1:end]
	while(l[:1]=='_'):
		l=l[1:]

	while(l[-1:]=='_'):
		l=l[:-1]
	
	if(l==''):
		pass
	else:
		noof+=l.count("_")+1
	
	s=s[:start]+'_'+s[end+1:]


while(s[:1]=='_'):
	s=s[1:]

while(s[-1:]=='_'):
	s=s[:-1]
	
less=0
	
s=s.split("_")

for i in s:
	less=max(less,len(i))

print(less,noof)


