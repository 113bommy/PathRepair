from math import log
x,y=[int(i) for i in input().split()]
b=x*log(y)
a=y*log(x)
if a==b:
    print('=')
if(a>b):
    print('>')
else:
    print('<')
