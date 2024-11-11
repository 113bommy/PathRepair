x,y=[int(x) for x in input().split()]
c=[0]*x
for i in range(y):
    z=[int(a) for a in input().split()]
    a=z.index(max(z))
    c[a]=c[a]+1
print(c.index(max(c))+1)