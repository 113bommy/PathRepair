s=list(map(int,input().split()))
n=int(s[0])
k=int(s[1])
l=int(s[2])
c=int(s[3])
d=int(s[4])
p=int(s[5])
nl=int(s[6])
np=int(s[7])

a=(k*l)//nl
b=d*c
s=p//np
r=min(a,b,s)//n
print(r)