x=input()
y=input()
x=int(x,2)
y=int(y,2)
z=bin(x^y).replace("0b","")
if len(str(z))<len(str(x)):
    z='0'*(len(str(x))-len(str(z)))+z
print(z)

