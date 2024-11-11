import sys

    
def main():
    #n = iinput()
    #k = iinput() 
    #m = iinput() 
    n = int(sys.stdin.readline().strip()) 
    #n, k = rinput()
    #n, m = rinput()
    #m, k = rinput()
    #n, k, m = rinput()
    #n, m, k = rinput()
    #k, n, m = rinput()
    #k, m, n = rinput() 
    #m, k, n = rinput()
    #m, n, k = rinput()
    #n, t = map(int, sys.stdin.readline().split())
    q = list(map(int, sys.stdin.readline().split()))
    #q = linput()
    res = []
    ans = sum(q)
    if ans % n != 0:
        print(-1)
        return 0
    ans //= n
    for i in range(1, n):
        t = q[i] % (i + 1)
        if t > 0:
            res.append([1, i + 1, i + 1 - t])
        q[i] += i + 1 - t
        res.append([i + 1, 1, q[i] // (i + 1)])
        q[0] += q[i]
        q[i] = 0
    for i in range(1, n):
        res.append([1, i + 1, ans])
    print(len(res))
    for i in res:
        print(*i)
    
           
        
            
    
    
    
    
    
    
            
                
        
    
            
        

            
        
    
                
    
    
    
            
    
        
    

for i in range(int(sys.stdin.readline().strip()) ):
    main()
    
