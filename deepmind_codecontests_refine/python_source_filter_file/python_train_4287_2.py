a=list(input().split())
ar1=[]
ar2=[]
for i in a:
    ar1.append(int(i[0]))
    ar2.append(i[1])
s=set()
for i in range(3):
    for j in range(i+1,3):
        if ar2[i]==ar2[j]:
            s.add(i)
            s.add(j)
if len(s)==0:
    print(2)
elif len(s)==2:
    i1=s.pop()
    i2=s.pop()
    if abs(ar1[i1]-ar1[i2])<=1:
        print(1)
    else:
        print(2)
else:
    ar1.sort()
    d1=ar1[1]-ar1[0]
    d2=ar1[2]-ar1[1]
    if d1==0:
        if d2==0:
            print(0)
        else:
            print(1)
    elif d1==1:
        if d2==1:
            print(0)
        else:
            print(1)
    elif d1==2 or d2==2:
        print(1)
    else:
        if d2==0 or d2==1:
            print(1)
        else:
            print(2)
        