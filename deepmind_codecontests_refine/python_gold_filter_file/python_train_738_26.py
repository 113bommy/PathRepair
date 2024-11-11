try:
    def pr(n):
        if (n <= 1) : 
            return False
        if (n <= 3) : 
            return True
    
        if (n % 2 == 0 or n % 3 == 0) : 
            return False
    
        i = 5
        while(i * i <= n) : 
            if (n % i == 0 or n % (i + 2) == 0) : 
                return False
            i = i + 6
        return True
    import math
    m=int(input())
    if pr(m)==True:
        print(1)
    else:
        if m%2==0:
            print(m//2)
        else:
            p=int(math.sqrt(m)+1)
            
            for i in range(2,p):
                if pr(i)==True and m%i==0:
                    k=i
                    break
            m=m-k
            l=m//2
            print(l+1)
    
    #where is Bushra,this is definitely not me!!
except:
    pass