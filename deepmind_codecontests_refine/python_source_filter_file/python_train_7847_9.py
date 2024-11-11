z=[int(p) for p in input().split()]
m=z[2]
lst=[]
lst.append(z[0])
lst.append(z[1])
tempi=min(lst)
tempa=max(lst)

count=0
fibo=[]


n=1000000000000000000
def fib(n):
        
        a, b = 0, 1
        while b < n:
                fibo.append(b)
                a, b = b, a+b
    


def add(m):
        n=10**18
        tempi=min(lst)
        tempa=max(lst)
        count=0
        if(tempi>0 and tempa>0 and m>tempa):
                fib(n)
                for p in range(1,len(fibo)+1):
                        if(((fibo[p]*tempa)+ (fibo[p-1]*tempi))>=m):
                                count+=p
                                return count
        elif(tempi==0 or tempa==0):
                count=1
                fib(n)
                tempi=tempa+(tempi)
                for p in range(1,len(fibo)):
                        if(((fibo[p]*tempa)+ (fibo[p-1]*tempi))>=m):
                                count+=p
                                return count

        elif(tempi<0 and tempa>0):
                val=(-(tempi)//tempa)+1
                count=val
                tempi=tempa+(val*tempi)
                fib(n)
                for p in range(1,len(fibo)):
                        if(((fibo[p]*tempa)+ (fibo[p-1]*tempi))>=m):
                                count+=p
                                return count

        





if(tempi>0 and tempa>0 and m>tempa):
        cou=add(m)
        print(cou)

elif(tempi>0 and tempa>0 and m<=tempa):
        print(0)

elif(tempi==0 ):
        if(tempi==0 and tempa==0 and m>0):
                print(-1)
        elif(tempi==0 and tempa==0 and m<=0):
                print(0)
        elif(tempa==0 and tempi<0 and m>0):
                print(-1)
                
        else:
                cou=add(m)
                print(cou)
elif(tempi<0 and tempa>0):
        if(m<=tempa):
                print(0)
        else:
                cou=add(m)
                print(cou)
elif(tempi<0 and tempa==0):
        if(m>0):
                print(-1)
        else:
                print(0)
elif(tempi<0 and tempa<0):
        if(m>=0):
                print(-1)
        elif(m<0 and m<=tempa):
                print(0)
        elif(m<0 and m>tempa):
                print(-1)

        


        
                
                
                        
                        
                                
                        
                


                        
                        
                        
