t = int(input())
while t!=0:  
    n = int(input())
    for i in range (2,31):
        if n%(2**i-1) ==0:
            print(int(n/(2**i-1)))
            break;
            
    t -=1        