def fact(n):
    if n==1:
        return 1
    elif n==2:
        return 2
    elif n==3:
        return 2
    else:
        c=0
        x=int(n**0.5)
        if x*x==n:
            for i in range(1,x):
                if n%i==0:
                    c+=2
            c+=1
            return c
        else:
            x=x+1
            for i in range(1,x+1):
                if n%i==0:
                    c+=2
            return c
            
                    
n=int(input())
print(fact(n))
