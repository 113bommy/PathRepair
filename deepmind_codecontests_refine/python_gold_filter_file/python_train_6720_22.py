

"""
instagram : essipoortahmasb
telegram channel : essi_python

"""
Mishka = 0
Chris = 0
i = input
for j in range(int(i())):
    a,b=map(int,i().split())
    if a > b:
        Mishka+=1
    elif a < b:
        Chris+=1
    else:
        pass

if Mishka > Chris:
    print("Mishka")
elif Mishka < Chris:
    print("Chris")
else:
    print("Friendship is magic!^^")
