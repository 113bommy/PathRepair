

R = lambda:map(int,input().split())

a , b, c, d = R()

misha = max((3*a)//10, a - (a//250) * c)
vasha = max((3*b)//10, b - (b//250) * d)

if misha > vasha:
    print("Misha")
elif vasha > misha:
    print("Vasya")
else:
    print("TIE")

    
    