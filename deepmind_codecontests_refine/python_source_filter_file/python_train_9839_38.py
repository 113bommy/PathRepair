import math
t=int(input())
for i in range(t):
    num=int(input())
    sum=sum2=0
    k=0
    while True:
        if int(2**k)>=num:
            break;
        else:
            k+=1
    for i in range(k+1):
        sum2+=2**i
    sum=(num*(num+1))//2
    print(sum-2*sum2)