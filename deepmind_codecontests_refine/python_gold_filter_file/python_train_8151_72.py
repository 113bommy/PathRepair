a=[int(i) for i in input().split()]
n=a[0]
k=a[1]
l=a[2]
c=a[3]
d=a[4]
p=a[5]
nl=a[6]
np=a[7]
re=int(min(k*l/nl,min(c*d, p/np))//n)
print(re)