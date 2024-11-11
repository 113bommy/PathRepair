n,m,*t=map(int,open(0).read().split())
a=sorted(t[:n])[::-1]
m=0
for c,b in sorted(zip(t[n+1::2],t[n::2]))[::-1]:
 while a*b and c>a[-1]:m+=c;b-=1;a.pop()
print(m+sum(a))