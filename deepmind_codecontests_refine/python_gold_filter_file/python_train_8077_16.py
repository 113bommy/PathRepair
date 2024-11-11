ab=input()
a=int(ab.split(" ")[0])
b=int(ab.split(" ")[1])

a1=int(a**(1/2))
b1=int(((4*b+1)**(1/2)-1)/2)

if a1-b1>=1:
    print ("Valera")
else:
    print ("Vladik")