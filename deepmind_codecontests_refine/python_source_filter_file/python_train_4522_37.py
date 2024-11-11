p1=input()
p2=input()
x1=ord(p1[0])-96
x2=ord(p2[0])-96
y1=int(p1[1])
y2=int(p2[1])
z=min(abs(x2-x1),abs(y2-y1))
moves=z
ar1=[]
if(x2>x1 and y2>y1):
    x1+=z
    y1+=z
    for c in range(z):
        ar1.append('RU')
elif(x2>x1 and y2<y1):
    x1+=z
    y1-=z
    for c in range(z):
        ar1.append('RD')
elif(x2<x1 and y2<y1):
    x1-=z
    y1+=z
    for c in range(z):
        ar1.append('LU')
else:
    x1-=z
    y1-=z
    for c in range(z):
        ar1.append('LD')
if(x2>x1):
    moves+=(x2-x1)
    for c in range(x2-x1):
        ar1.append('R')
elif(x2<x1):
    moves+=(x1-x2)
    for c in range(x1-x2):
        ar1.append('L')
elif(y2>y1):
    moves+=(y2-y1)
    for c in range(y2-y1):
        ar1.append('U')
else:
    moves+=(y1-y2)
    for c in range(y1-y2):
        ar1.append('D')
print(moves)
for sv in range(len(ar1)):
    print(ar1[sv])
