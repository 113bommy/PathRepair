def stairs(n):
    if n==1:
        return 1
    k=n
    temp=0
    cnt=0
    p=0
    i=1
    while n>0:
        temp=(i*(i+1))//2
        n-=temp
        if n>0:
            cnt+=1
            p+=1
            i+=2**p
        else:
            break
    return cnt


t=int(input())
for i in range(t):
    print(stairs(int(input())))
