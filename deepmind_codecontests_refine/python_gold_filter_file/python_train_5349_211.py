t=input()
n=len(t)
if(n>0 and t[0].islower()):
    print(t[0].upper()+t[1:])
else:
    print(t)