import math
def prime(n):
    a=set()
    if n%2==0:
        while(n%2==0):
            a.add(n//2)
            n=n//2
            
    p=math.sqrt(n)
    p=int(p)
    for i in range(3,p+1,2):
        if n%i==0:
            while(n%i==0):
                a.add(n//i)
                n=n//i
    a.add(1)
    return a
            
        

n=int(input())
a=prime(n)
a=list(a)
if n==1:
    print(1)
    exit()
a.append(n)
a.sort(reverse=True)

print(*a)
