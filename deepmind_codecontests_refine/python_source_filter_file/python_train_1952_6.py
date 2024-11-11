import time
import math
start = time.time()
x,y = map(int,input().split(' '))
a = y*math.log(x,10)
b = x*math.log(x,10)
if a>b:
    print('>')
else:
    if a<b:
        print('<')
    else:
        print('=')
end = time.time()

