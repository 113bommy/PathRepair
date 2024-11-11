import math
s=input()
r=float(s)
def okrugl(fl):
    return (round(fl*1000000)/1000000)
flag=1
for a in range(1,11):
    for h in range(1,11):
        
        #print(((a*h)/(math.sqrt(a*a+h*h*4))))0
        
        if okrugl((a*h)/(math.sqrt(a*a+h*h*4)))==r:
            if flag:
                print(a," ",h)
                flag=0
