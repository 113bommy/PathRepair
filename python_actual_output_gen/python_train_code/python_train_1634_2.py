x=input()
if(len(x)>1):
    if(x.isupper()):
        print(x.lower())
    elif(x[0].islower() and x[1:].isupper()):
        y=x[0].upper()
        z=x[1:].lower()
        print(y+z)
    else:
        print(x)
else:
    if(x.islower()):
        print(x.upper())
    else:
        print(x)
    