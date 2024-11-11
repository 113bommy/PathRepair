from fractions import gcd

t,w,b = map(int,input().split())
if w>b: w,b=b,w
lcm = w//gcd(w,b)*b
ans = (t//lcm+1)*w-1
if t%lcm+1 < w:
	ans -= w - t%lcm+1
g = gcd(ans,t)
print("%d/%d"%(ans//g,t//g))