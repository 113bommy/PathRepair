for x in range(int(input())):
    n = int(input())
    
    
    
    c=0
    p=[]
    if(n==1):
        print(n)
        print(n)
    else:
        while(n>1):
            k=len(str(n))
            c+=1
            z=n//10**(k-1)
            p.append(z*10**(k-1))
            n=n%(10**(k-1))
        print(c)
        print(*p)