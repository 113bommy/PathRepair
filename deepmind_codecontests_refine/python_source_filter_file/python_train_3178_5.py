



n,b,p = map(int,input().split())



bot =  2*b+1
to = p*n
bo =0



if n==1:
    print(0,0)
else:
    while n>1:
        for k in range(1,11):
            u=2**k
            #print(n,u)
            if u< n:
                pass
            else:
                if u == n:
                    bo+= (n//2)*bot
                    n=2**(k-1)
                else:

                    bo+= (2**(k-2))*bot
                    h= n-(2**(k-1))
                    n = 2**(k-2)+h
                break
            
            
    print(bo,to)
                
                
