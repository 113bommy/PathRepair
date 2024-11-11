s=input()
x=len(s)
if(x%2==0):
	t=""
	for i in range(0,x//2):
		t=s[x-1-i]+t
		t=s[i]+t
	print(t)
else:
	t=s[0]
	for i in range(1,x//2+1):
		t=s[x-1-i]+t
		t=s[i]+t
	print(t)





