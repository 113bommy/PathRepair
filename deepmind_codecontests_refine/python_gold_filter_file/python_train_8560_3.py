kk= int(input())
for ii in range(kk): 
    x,n,m= input().split()
    x=int(x)
    n=int(n)
    m=int(m)
    while((n+m)>0 and x>0):
        if(x>40):
            if(n>0):
                n-=1
                x=int(x/2)+10
            else:
                if(m>0):
                    m-=1
                    x=x-10    
        elif(x<21):
            if(m>0):
                m-=1
                x=x-10
            else:
                if(n>0):
                    n-=1
                    x=int(x/2)+10
        else:
            if(n>0):
                n-=1
                x=int(x/2)+10
            else:
                m-=1
                x=x-10
                
    if(x<=0):
        print("YES")
    else:
        print("NO")    


