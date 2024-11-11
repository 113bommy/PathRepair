_,*t=open(0).read().split()
t=map(int,t)
s=0
m=9e9
for a,b in zip(t,t):
 s+=a
 if a>b:m=min(m,b)
print(max(0,s-m))