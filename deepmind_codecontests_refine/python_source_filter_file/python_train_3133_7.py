def delfromleft(s,t):
	d=0
	i=len(s)-1
	if s[len(s)-1]!=t[len(t)-1] :
		return len(s)+len(t)
	else :
		for j in range(len(t)-1,-1,-1):
			if s[i]==t[j]:
				d+=1
			else :
				break
			i=i-1
	return (len(s)+len(t))-(d*2)
a=list(input())
b=list(input())
print(delfromleft(a,b))