s = input()
v1=0
v2=0
v3=0
v4=0
val=0
for x in range(0,len(s)):
	if s[x]=="n":                             
		v1=v1+1
	elif s[x]=="i":
		v2=v2+1
	elif s[x]=="e":
		v3=v3+1
	elif s[x]=="t":
		v4=v4+1

v1=v1//2 #1
v3=v3//3 #1
while (v1!=0 and v3!=0 and v2!=0 and v4!=0):
		val=val+1
		v1=v1-1
		v2=v2-1
		v3=v3-1
		v4=v4-1



print(val);
