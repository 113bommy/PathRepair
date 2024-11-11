t=int(input())
while(t>0):
	n=input()
	l=len(n)
	n=n[0]
	print(int((int(n)-1)*10+(l*(l+1)/2)))
	t-=1
