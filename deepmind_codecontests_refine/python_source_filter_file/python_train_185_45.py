def abc(n,p):
    ans=1
    b = 2
    if n==1:
        return p
    e=0
    while p%b == 0:
        p = p//b
        e +=1
    e=int(e//n)
    if e:
        ans*=(b*e)
    b+=1
    while b**2<=p:
        e=0
        while p%b == 0:
            p = p//b
            e +=1
        e=int(e//n)
        if e:
            ans*=(b**e)
        b+=2
    return ans

n,p=map(int,input().split())
print(abc(n,p))
