def isprime(x):
    if x==1:
        return False
    for i in range(2,x):
        if x%2==0:
            return False
    return True

def f(n):
    for p in range(1,2*n):
        if not isprime(p) and isprime(n-1+p):
            break
    for i in range(n):
        s=[]
        for j in range(n):
            if j==i:
                s.append(p)
            else:
                s.append(1)
        print(' '.join([str(t) for t in s]))

T=int(input())
for case in range(T):
    n=int(input())
    f(n)