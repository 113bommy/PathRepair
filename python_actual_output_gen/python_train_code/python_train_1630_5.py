n=int(input())
s=input()
l=s.count("(")
r=s.count(")")
ans="("
x=":("
if n&1 or l>n//2 or r>n//2:
	print(x)
else:
	l1=(n//2-l)
	r1=(n//2-r)
	l,r=0,0
	ans=""
	i=0
	while(i<len(s)):
		if s[i]=="?":
			if l1>0:
				ans+='('
				l+=1
				l1-=1
			else:
				ans+=')'
				r+=1
				r1-=1
		elif s[i]=="(":
			l+=1
			ans+='('
		else:
			r+=1
			ans+=')'

		if l==r and i!=len(s)-1:
			ans=":("
			break
		i+=1

	print(ans)
