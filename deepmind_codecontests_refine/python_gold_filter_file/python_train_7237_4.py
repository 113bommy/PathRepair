al=input()
d=al.split()
n=int(d[0])
a=int(d[1])
t=0
s1=[]
s2=[]

for i in range(1,n,2):
	s1.append(i)

for i in range(n,1,-2):
	s2.append(i)

if a%2==0:
	for i in range(len(s2)):
		t+=1
		if s2[i]==a:
			break
else:
	for i in range(len(s1)):
		t+=1
		if s1[i]==a:
			break

print(t)