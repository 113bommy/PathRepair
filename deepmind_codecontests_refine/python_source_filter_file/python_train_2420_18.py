from math import pow
t=int(input())
for i in range(t):
    n=int(input())
    sum1=0
    sum2=0
    for i in range(1,n):
        if i<n//2:
            sum1+=pow(2,i)
        else:
            sum2+=pow(2,i)
    sum1+=pow(2,n)
    print(sum1-sum2)
