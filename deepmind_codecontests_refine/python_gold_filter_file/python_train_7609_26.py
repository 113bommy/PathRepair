
n=int(input())

l=list(map(int,input().split()))

def heist(l):
	l.sort()
	c=0
	for i in range(len(l)-1):
		c+=l[i+1]-l[i]-1
	return c

print(heist(l))
