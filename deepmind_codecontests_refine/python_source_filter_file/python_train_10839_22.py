import math
t=int(input())
lst=[]
for i in range(0,t):
    a,b,k = input().split();
    a=int(a)
    b=int(b)
    k=int(k)
    if k%2 == 0:
        #print(round((k/2)*a-(k/2)*b))
        lst.append(int(((k/2.0)*a)-((k/2.0)*b)))
    else:
        r=math.ceil(k/2)
        l=k//2
        #print((r*a)-(l*b))
        lst.append((r*a)-(l*b))

for a in lst:
    print(a)
