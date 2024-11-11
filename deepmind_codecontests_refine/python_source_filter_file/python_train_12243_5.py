s=input()
a,b =int(s[0]),int(s[1])
c,d =int(s[3]),int(s[4])
x=a*10+b*1
y=c*10+d*1
if x==5 and y>50:
    print((60 - y) + (60 * (10 - (x + 1))) + 1)
if x==15 and y>51:
    print((60 - y) + (60 * (20 - (x + 1))) + 2)

elif x>5 and x<10 :
    print((60-y)+(60*(10-(x+1)))+1)
elif x>15 and x<20 :
    print((60 - y) + (60 * (20 - (x + 1)))+2)
elif(x==23 and y >32):
    print(60-y)
elif(x==23 and y<=32):
    print(32-y)
else:
    x1=b*10+a*1
    if x1 >= y:
        print(x1-y)
    else:
        print(x1+10 + (60-y))
