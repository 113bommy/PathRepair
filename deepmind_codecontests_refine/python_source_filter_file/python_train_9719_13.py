l=list(map(int,input().split()))
a=l[0]/l[1]
x=(l[2]/a)**0.5
y=a*x
z=l[0]/y
an=4*(x+y+z)
print(an)