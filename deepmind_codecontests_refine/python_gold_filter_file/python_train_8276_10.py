x=input()
v=int(input())
y=x.split(":")
var3=int(y[0])*60 + int(y[1]) + v
h=var3//60
m=var3%60

        
if (h==24) or(h==0):
    if m<10:
        print("00:0"+str(m))
    else:
        print("00:"+str(m))
elif h>24:
    h=h%24
    if m<10 and h>9:
        print( str(h)+":0"+str(m))
    elif h<10 and m<10:
        print( "0"+str(h)+":0"+str(m))
    elif h<10 and m>=10:
        print( "0"+str(h)+":"+str(m))
    else:
        print(str(h)+":"+str(m))
else:
    if (m<10) and (h>9):
        print( str(h)+":0"+str(m))
    elif h<10 and m<10:
        print( "0"+str(h)+":0"+str(m))
    elif (h<10) and (m>=10):
        print( "0"+str(h)+":"+str(m))
    else:
        print(str(h)+":"+str(m))
