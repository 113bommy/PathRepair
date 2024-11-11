i=input()
s=set(i)
def F(c):
	l=[i+1 for i,x in enumerate(i) if x==c]
	d=(y-x for x,y in zip(l,l[1:]))
	return max(l[0],len(i)-l[-1]+1,*d)
print(min(map(F,s)))