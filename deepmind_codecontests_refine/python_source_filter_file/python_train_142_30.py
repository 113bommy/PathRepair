
#A. Helpful Maths

x=input().split('+')
y=list(map(int,x))
y=sorted(y)
z=""
for val in y:
    z+=str(val)
    z+=" + "
print(z[0:-2])