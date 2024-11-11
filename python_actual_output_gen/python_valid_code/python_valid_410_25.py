n=int(input())
s=""
for i in range(0,n):
	if i==0:
		s+="I hate it"
	elif i%2!=0:
		s=s[:-3]
		s+=" that i love it"
	elif i%2==0:
		s=s[:-3]
		s+=" that i hate it"
	
print(s)