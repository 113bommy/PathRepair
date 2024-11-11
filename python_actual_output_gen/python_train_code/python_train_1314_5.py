import math
n=int(input())
if n==2:
    exit(print(1))
if n%2==0:
    print(2);exit()
flag=0
for i in range(2,math.ceil(n**.5)+1):
    if n%i==0:
        flag=1;break
if flag==0:
    print(1);exit()
else:
    for i in range(2,math.ceil((n-2)**.5)+1):
        if n%i==0:
            print(3);exit()
    print(2)
        