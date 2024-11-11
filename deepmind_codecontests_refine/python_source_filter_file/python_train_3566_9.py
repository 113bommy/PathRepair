q = int(input())

for i in range(q):
    n = int(input())
    
    lst = [int(x) for x in input().split()]
    
    if (n == 1):
        print(lst[0])
        exit()
    
    se = so = mx = mn = 0
    k = 1
    
    while(k < n):
        
        if (se >= 0):
            se+=(lst[k]-lst[k-1])
        else:
            se = lst[k]-lst[k-1]
        k+=2
        #print(mx,se)
        mx = max(mx, se)
    #print(mx)
    
    k = 2
    
    while(k < n):
        
        if (se <= 0):
            so+=(lst[k]-lst[k-1])
        else:
            so = lst[k]-lst[k-1]
        mn = min(mn, so)
        k+=2
    #print(mn)
    
    ret = 0
    k = 0
    mx = max(abs(mn), mx)
    while(k<n):
        ret+=lst[k]
        k+=2
    #print(ret, mx)
    if (mx > 0):
        print(ret+mx)
    else:
        print(ret)
        
        