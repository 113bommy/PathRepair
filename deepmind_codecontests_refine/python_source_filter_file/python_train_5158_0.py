[n,m]=[int(x) for x in input().split()]
a=[n//5 for i in range(0,5)]
b=[m//5 for i in range(0,5)]
for i in range(1,n%5+1):
    a[i]+=1
for i in range(1,m%5+1):
    b[i]+=1
c=a[0]*b[0]
for i in range(1,5):
    c+=a[i]*b[4-i]
print(c)
