import math

def ncr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

s0 = input()
s1 = input()
p0 = 0
p1 = 0
l = len(s0)
r = 0
for c in s0:
	if c == '+': p0+=1
	elif c == '-': p0-=1

for c in s1:
	if c == '+': p1+=1
	elif c == '-': p1-=1
	else : r+=1

if abs(p1-p0)>r :
	print(0)
else :
	h = r-abs(p1-p0)
	if h%2 == 0 :
		print((ncr(r,(h//2))/(2**r)))
	else :
		print(0)

