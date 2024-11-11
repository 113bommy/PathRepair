def ter(n):
	l=[]
	a=0
	su=0
	while n>1:
		r=n%2
		l.append(r)
		n=n/2
	for e in l:
		su=su+(pow(3,a)*e)
		a=a+1
	return su









def sea(n):
	l=0
	h=1000000000000000001
	while l<=h:
		m=(l+h)//2
		v1=ter(m)
		v2=ter(m+1)
		if (n==v1):
			return n
		elif (n<v2 and n>v1):
			return v2
		elif(n<v1):
			h=m-1
		else:
			l=m+1










if __name__ == '__main__':
	q=int(input())
	while q>0:
		n=int(input())
		ans=sea(n)
		print(ans)
		q=q-1
