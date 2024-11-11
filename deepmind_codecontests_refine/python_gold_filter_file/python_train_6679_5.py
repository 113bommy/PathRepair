n=int(input())
s=input()
l=[]

for i in range(0,n):
	if(len(l)%2==0 or s[i]!=l[-1]):
		l.append(s[i])
	

		
#print(l)
if(len(l)%2!=0):
	l.pop()
	print(n-len(l))
	print("".join(l))
else:
	print(n-len(l))
	print("".join(l))
	



	
