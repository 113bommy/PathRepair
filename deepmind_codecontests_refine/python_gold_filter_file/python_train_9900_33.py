import math
n,k=map(int,input("").split(' '))
if k>n:
    if k%2==0:
        print(max(0,int(n-k/2)))
    else:
        print(max(0,n-math.floor(k/2)))
else:
    print(max(0,math.ceil(k/2)-1))