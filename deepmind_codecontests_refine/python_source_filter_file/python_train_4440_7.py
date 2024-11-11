import math
r,g,b=map(int,input().split())
r,g,b=math.ceil(r/2),math.ceil(g/2),math.ceil(b/2)
large=max(r,g,b) 
if(large==0):
    print("0")
elif(large==b and b>0):
    print(32+3*(b-1))
elif(large==g and g>0):
    print(32+2*(g-1))
else:
    print(r+31)