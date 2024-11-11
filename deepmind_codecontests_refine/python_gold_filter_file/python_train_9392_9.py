# -*- coding: utf-8 -*-
t=input()
for i in range(0,int(t)):
    inp=input()
    num=inp.split()
    if(int(num[0])>int(num[1])):
        a=int(num[1])
        b=int(num[0])
    else:
        a=int(num[0])
        b=int(num[1])
    c=int(num[2])
    r=int(num[3])
    mini=c-r
    maxi=c+r
    if((maxi<a or mini>b)or ((b==c or a==c) and r==0)):
        cover=len(range(a,b))
        print (cover)
    elif((mini<=a and maxi>=b) or a==b):
        print (0)
    elif((maxi<=b and mini>=a)):
        cover=len(range(a,b))-(maxi-mini)
        print (cover)
    elif(maxi<b and mini<=a):
        cover=len(range(a,b))-(maxi-a)
        print (cover)
    elif(maxi>=b and mini>a):
        cover=len(range(a,b))-(b-mini)
        print (cover)    
