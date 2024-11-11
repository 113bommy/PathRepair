x,y=map(int,input().split())
mauka=0 
while 1:
    if mauka==0:
        if x>=2 and y>=2:
            x=x-2 
            y=y-2
        elif x>=1 and y>=12:
            x=x-1 
            y=y-12
        elif x==0 and y>=22:
            y=y-22
        else:
            culprit=0 
            break 
    else:
        if y>=22:
            y=y-22
        elif y>=12 and x>=1:
            y=y-12
            x=x-1 
        elif y>=2 and x>=2:
            x=x-2 
            y=y-2
        else:
            culprit=1 
            break 
   # print(x,y)
    mauka=1-mauka
if culprit:
    print('Ciel')
else:
    print('Hanako')