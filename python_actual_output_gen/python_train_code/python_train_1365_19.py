s1=input()
s2=input()
if len(s1)!=len(s2):
	print("No")
	exit()
f=0
v=["a","e","i","o","u"]
c=[chr(i) for i in range(97,97+26,1) if i not in v]
for i in range(len(s1)):
	if ((s1[i] in v and s2[i] in v) or (s1[i] in c and s2[i] in c))==False:
		f=1
		break
if f==1:
	print("No")
else:
	print("Yes")
