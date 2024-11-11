a=int(input())
vav=input().split()
max1=int(vav[0])
min1=int(vav[1])
vav=input().split()
sovp=True
b=False
n=False
if int(vav[0])>max1:
    max2=max1
    max1=int(vav[0])
    b=True
else:
    max2=int(vav[0])
if int(vav[1])<min1:
    min2=min1
    min1=int(vav[1])
    n=True
else:
    min2=int(vav[1])
if b==True and n==True:
    sovp=True
elif b==True or n==True:
    sovp=False


for i in range(a-2):
    vav=input().split()
    vvod1=int(vav[0])
    vvod2=int(vav[1])
    b=False
    n=False
    if vvod1>max2:
        if vvod1>max1:
            max2=max1
            max1=vvod1
            b=True
        else:
            max2=vvod1

    if vvod2<min2:
        if vvod2<min1:
            min2=min1
            min1=vvod2
            n=True
        else:
            min2=vvod2
    if b==True and n==True:
        sovp=True
    elif b==True or n==True:
        sovp=False



if sovp==True:
    otv=min2-max2
else:
    case1=min1-max2
    if case1<0:
        case1=0
    case2=min2-max1
    if case2<0:
        case2=0
    if case1>case2:
        otv=case1
    else:
        otv=case2
print(otv)
