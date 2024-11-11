n = int(input())
if n==1 or n==2:
    print(-1)
else:
    m = n
    cnt = 0
    while n%2==0:
        n //= 2
        cnt += 1
    if n==1:
        print(3*2**(cnt-2),5*2**(cnt-2))
    else:
        x = (n-1)//2
        print(2*x*(x+1)*(2**cnt),(2*x*x+2*x+1)*(2**cnt))