
n, x = map(int,input().split())

p = 1

t = 0

i = 0

while(i<n):

	l,r = map(int,input().split())

	z = ((l-p)/x)*x

	t = t+(r-(p+z)+1)

	i = i+1

	p = r+1

print (t)
    
