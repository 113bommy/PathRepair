n=int(input())
ge=[]
le=[]
for i in range(n):
    sign,num,out=input().split()
    num=int(num)
    if out=="Y":
        if sign==">":
            ge.append(num+1)
        elif sign==">=":
            ge.append(num)
        elif sign=="<":
            le.append(num-1)
        else:
            le.append(num)
    else:
        if sign==">":
            le.append(num-1)
        elif sign==">=":
            le.append(num)
        elif sign=="<=":
            ge.append(num)
        else:
            ge.append(num+1)
import random
if len(ge)>0 and len(le)>0:
    if max(ge)>min(le):
        print("Impossible")
    elif max(ge)<min(le):
        print(random.randrange(max(ge),min(le)))
    else:
        print(min(le))
elif len(ge)==0:
    print(min(le))
elif len(le)==0:
    print(max(ge))
