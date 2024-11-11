t=int(input())
for _ in range(t):
    n=int(input())
    sum1=0
    for x in range(1,(n//2)+1):
        sum1=sum1+pow(x,2)
    print(sum1*8)