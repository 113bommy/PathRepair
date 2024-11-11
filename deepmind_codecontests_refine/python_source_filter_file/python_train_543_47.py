n = int(input()) ; 
for k in range(n) : 
    m = int(input()) ;
    if m ==1 : 
        print("0") ; 
    else : 
        print((m*((m-1)/2)*((m-1)/2 + 1))/3 * 4) 