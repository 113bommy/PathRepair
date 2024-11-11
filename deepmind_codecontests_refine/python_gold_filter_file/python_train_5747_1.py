import sys
try:
	fin = open('in')
except:
	fin = sys.stdin

n=int(fin.readline())
p=[]
i=2
while i*i<=n:
	if n%i==0:
		p.append(i)
		while n%i==0:n//=i
	i += 1
if n>1:p.append(n)
if len(p)==1:print(p[0])
else:print(1)