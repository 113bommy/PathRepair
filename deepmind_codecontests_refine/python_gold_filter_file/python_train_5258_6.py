import sys

letras="abcdefghijklmnopqrstuvwxyz"

def distinto(a,b):
	for lc in range(26):
		c=letras[lc]
		if (a!=c and b!= c): return c

s3=""
l=0

for line in sys.stdin:
	if l==0:
		n,t=map(int,line.split())
	if l==1:
		s1=line
	else: s2=line
	l+=1
dist=0
for i in range(n):
	if (s1[i]!=s2[i]): dist+=1
if (t<int((dist+1)/2)):
	s3+= str(-1)
elif (t>=dist) :
	igdist=t-dist
	for i in range(n):
		if (s1[i]!=s2[i]):
			s3+= distinto(s1[i],s2[i])
		else:
			if (igdist==0):
				s3+= s1[i]; 
			else:
				s3+= distinto(s1[i],s2[i])
				igdist-=1
else :
	distdist=dist-t
	alter=1
	for i in range(n):
		if (s1[i]==s2[i]):
			s3+= s1[i]
		else:
			if (distdist==0):
				s3+= distinto(s1[i],s2[i]);
			else:
				if (alter==1):
					s3+= s1[i]
					alter=2
				else:
					s3+= s2[i]
					alter=1
					distdist-=1
print (s3)
