_,a=open(0)
*a,=map(int,a.split())
m=max(a)
c=[0]*-~m
for i in a:c[i]+=1
print(sum(c[:m//2])<1and~m%2==c[m//2]and all(c[i+1]>1for i in range(m//2,m))and'Possible'or'Impossible')