from bisect import*
n,d,a,*t=map(int,open(0).read().split())
c=[0]*-~n
z=sorted(zip(*[iter(t)]*2))
s=0
for i,(x,h)in enumerate(z):
    c[i]+=c[i-1]
    h-=c[i]
    t=-h//a
    c[i]-=t*a
    c[bisect(z,(x+d+d,10e9))]+=t*a
    s-=t
print(s)