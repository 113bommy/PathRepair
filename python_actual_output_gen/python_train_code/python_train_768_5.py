t=int(input())
for i in range(t):
    n=int(input())
    a=0
    while n>=10:
        r=n%10
        n=int(n/10)
        a=+(n*10)
        n=n+r
    print(a+n)