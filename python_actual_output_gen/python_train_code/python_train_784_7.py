x=str(int(input("")))
y=str(int(input("")))

p=x.replace("0", "" , x.count("0"))
q=y.replace("0", "" , x.count("0"))

z=int(p)+int(q)
o=str(int(x)+int(y))
o=o.replace("0", "" , x.count("0"))
if(int(z)==int(o)):
    print("YES")
else:
    print("NO")

