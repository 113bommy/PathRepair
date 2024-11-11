a,b,s = map(str,input().split())
a = int(a)
if(s=='week') :
    if(a==6 or a==7) :
        print(53)
    else :
        print(52)
elif(s=='month') :
    if(a==30) :
        print(11)
    elif(a==31) :
        print(7)
    else:
        print(12)