import math
for t in range(int(input())):
    a,b=[int(k) for k in input().split()]
    if b>a:
        print(1)
    elif b==a:
        print(2)
    else:
        step=0
        if b==1:
            b+=1
            step+=1
        ans=int((math.log(a,b))+0.000000000000001)+1+step
        while b<a:
            b+=1
            step+=1
            if int((math.log(a,b))+0.000000000000001)+1+step<ans:
                ans=int((math.log(a,b))+0.000000000000001)+1+step
            else:
                break
        print(ans)
