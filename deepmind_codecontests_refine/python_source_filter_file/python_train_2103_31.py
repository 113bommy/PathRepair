import math
z=int(input())
i=0
while(i<z):
    l=list(map(int,input().split()))
    m=math.ceil(l[0]/float(l[2]))
    n=math.ceil(l[1]/float(l[3]))
    if m+n==l[4]:
        print(m,n)
    else:
        print(-1)
    i+=1