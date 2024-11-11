import math
n=int(input())
f=1
for i in range(2,math.ceil(math.sqrt(n))+1):
    if i!=n and n%i==0:
        f=0
        break
if f:
    print(1)
    print(n)
else:
    for i in range(n-2,1,-1):
        p=1
        for j in range(2,math.ceil(math.sqrt(i))+1):
            if j!=i and i%j==0:
                p=0
                break
        if p:
            num1=i
            n1=n-i
            break
    if n-n1==2 or n-n1==3:
        print(2)
        print(n1,n-n1)
    else:
        for i in range(2,n1):
            p1,p2=1,1
            for j in range(2,math.ceil(math.sqrt(i))+1):
                if j!=i and i%j==0:
                    p1=0
                    break
            if p1:
                for j in range(2,math.ceil(math.sqrt(n1-i))+1):
                    if j!=n1-i and (n1-i)%j==0:
                        p2=0
                        break
            if p1 and p2:
                print(3)
                print(num1,i,n1-i)
                break        
            
            