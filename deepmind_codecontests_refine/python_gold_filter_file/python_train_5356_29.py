p,n=input().split()
n=int(n)
p=int(p)
def f(n,p):
	l=[]
	for i in range(1,n+1):
		a=int(input())%p
		if a in l:
			return i
		l.append(a)
	return -1 
print(f(n,p))