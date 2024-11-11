n=int(input())
c=0
if n//10==0:
    print(10-n)
else:
    while True:
        x=10-n%10-1
        c+=(x+1)
        n+=(x+1)
        while n%10==0:
            n//=10
        if n//10==0:
            break
    print(c+9)


