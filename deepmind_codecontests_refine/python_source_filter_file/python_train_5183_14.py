n,*l=map(int,open(0).read().split())
p=0,0
d=p
for l in l:d+=max(l+d[-2],[d,p][len(d)&1][-1]),;p+=l+p[-2],
print(d[-1])