for _ in range(int(input())):
    
    a,b,c = map(int,input().split())
    
    if a>=c:
        print('-1',b)
        
    elif a==c//b:
        print(1,'-1')
        
    else:
        print('1',b)