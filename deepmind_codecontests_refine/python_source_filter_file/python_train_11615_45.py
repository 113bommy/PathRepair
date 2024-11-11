n=int(input())
s=input()
hr,mn=s[:2],s[3:]
h,m=int(hr),int(mn)
if n==24:
    if h<=24 and m<60:
        print(hr+":"+mn)
    elif h>24 and m>60:
        print('0'+hr[1]+":0"+mn[1])
    elif m>60:
        print(hr+":0"+mn[1])
    else:
        print("0"+hr[1]+":"+mn)
else:
    if h<13 and h>0 and m<60:
        print(hr+":"+mn)
    elif h==0 and m>=60:
        print("01:0"+mn[1])
    elif h==0 and m<60:
        print("01:"+mn)
    elif h>12 and m>60:
        print("0"+hr[1]+":0"+mn[1])
    elif m>60:
        print(hr+":0"+mn[1])
    elif hr[1]!='0':
        print('0'+hr[1]+":"+mn)
    else:
        print('10:'+mn)
