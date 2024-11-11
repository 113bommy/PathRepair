a=input()
c=0
for i in range(97,123):
	x=a.count(chr(i))
	if x>1:
	    c+=x-1

z=(26*(len(a)+1))-len(a)-c
print(z)
