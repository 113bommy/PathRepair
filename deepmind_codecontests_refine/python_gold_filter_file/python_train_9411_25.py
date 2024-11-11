a,b,c = map(int,input().split())

if a>=b and a>=c:
    if a>b+c:
        print('Impossible')
        
    elif a==b+c:
        print(b,0,c)
        
    else:
        i=2
        flag=0
        while b+c-i>=a:
            if a==b+c-i:
                print(b-(i//2),i//2,c-(i//2))
                flag=1
                break
            
            i+=2
            
        if flag==0:
            print('Impossible')
            

elif b>=a and b>=c:
    if b>a+c:
        print('Impossible')
        
    elif b==a+c:
        print(a,c,0)
        
    else:
        i=2
        flag=0
        while a+c-i>=b:
            if b==a+c-i:
                print(a-(i//2),c-(i//2),i//2)
                flag=1
                break
            
            i+=2
            
        if flag==0:
            print('Impossible')
            
            
elif c>=b and c>=a:
    if c>b+a:
        print('Impossible')
        
    elif c==b+a:
        print(0,b,a)
        
    else:
        i=2
        flag=0
        while b+a-i>=c:
            if c==b+a-i:
                print(i//2,b-(i//2),a-(i//2))
                flag=1
                break
            
            i+=2
            
        if flag==0:
            print('Impossible')