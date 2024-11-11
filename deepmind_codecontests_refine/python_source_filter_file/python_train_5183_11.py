n,*l=map(int,open(0).read().split())
p=0,0
d=p
i=0
for l in l:d+=max(l+d[-2],[d,p][i&1][-1]),;p+=l+p[-2],;i+=1
print(d[-1])