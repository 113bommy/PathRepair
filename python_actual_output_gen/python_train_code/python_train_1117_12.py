n,*t=map(int,open(0).read().split())
r=[0]+[1]*n
for a,b in zip(t[n::2],t[n+1::2]):r[a]&=t[a]>t[b];r[b]&=t[b]>t[a]
print(sum(r))