def alt(a,i,j):
	c=0
	now=i
	for k in range(len(a)):
		if(a[k]==i and now==i):
			now=j
		elif(a[k]==j and now==j):
			now=i
			c+=1
	return c*2
def main():
	for _ in range(int(input())):
		a=list(input())
		x=[i for i in range(10)]
		m=0
		for i in range(10):
			for j in range(10):
				if(i!=j):
					m=max(m,alt(a,str(i),str(j)))
				else:
					m=max(m,x.count(i))
		print(len(a)-m)
main()