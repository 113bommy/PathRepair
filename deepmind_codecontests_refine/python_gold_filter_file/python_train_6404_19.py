x1=input()
y1=input()
x=int(x1,2)
y=int(y1,2)
z=bin(x^y).replace("0b","")
if len(str(z))<len(str(x1)):
    z='0'*(len(str(x1))-len(str(z)))+z
print(z)

