

def isprm(x):
    if x==0 or x==1:
        return False
    
    for i in range(2,x):
        if i*i>x:
            break
        if n%i==0:
            return False
    
    return True

n=int(input())


if isprm(n):
    print(1)
elif n%2==0 or isprm(n-2):
    print(2)
else:
    print(3)