line=['a','b','c','d','e','f','g','h']
a=str(input())
b=str(input())
x=line.index(list(a)[0])-line.index(list(b)[0])
y=int(a[1])-int(b[1])
i=0
j=0
k=0
if abs(x)<abs(y):
    k=1
print(max(abs(x),abs(y)))
while i<min(abs(x),abs(y)):
    if x>0 and y>0:
        print('LD')
    if x<0 and y>0:
        print('RD')
    if x>0 and y<0:
        print('LU')
    if x<0 and y<0:
        print('RU')
    i=i+1
while j<abs(abs(x)-abs(y)):
    if k==1 and y<0:
        print('U')
    if k==1 and y>0:
        print('D')
    if k==0 and x<0:
        print('R')
    if k==1 and x>0:
        print('L')
    j=j+1    
