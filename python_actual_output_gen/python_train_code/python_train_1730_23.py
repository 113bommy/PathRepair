for _ in range(int(input())):
    a,b=[int(i) for i in input().split()]
    c=abs(a-b)
    r=c%5
    sum=c//5
    if c==0:
        sum=0
    elif r==1 or r==2:
        sum=sum+1
    else:
        sum=sum+2
    print(sum)
        
