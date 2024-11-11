import math
n=int(input())
if n==1 or n==2:
    print(1)
    print(1)
elif n==3:
    print(2)
    print('1','3',end=" ")
elif n==4:
    print(3)
    print('1','4','2',end=" ")
else:
    print(n)
    lst=[]
    k1=1
    k2=math.ceil(n/2) + 1
    for j in range(n):
        if j%2==0:
            lst.append(k1)
            k1+=1
        else:
            lst.append(k2)
            k2+=1
    for j in range(n):
        print(lst[j],end=" ")
