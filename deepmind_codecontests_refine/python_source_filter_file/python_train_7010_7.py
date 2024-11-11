a=input ()
b1=''
b2=''
p1=1
p2=0
for k in a:
    if (k!=' ') and p1:
        b1+=k
    elif(k!=' ') and p2:
        b2+=k
    elif(k==' '):
        if p1:
            p1=0
            p2=1
        elif p2:
            p2=0
#print(b1,' ',b2)            
deti=int(b2)
vzrosl=int (b1)
deneg=0
if (not vzrosl) and deti:
    print ('Impossible')
elif (deti>=vzrosl):
    print (deti,' ',vzrosl+deti-1)
elif (deti>0):
    print (vzrosl,' ',vzrosl+deti-1)
else:
    print (vzrosl,' ',vzrosl)
