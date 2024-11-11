for u in range(int(input())):
    n = int(input())
    x = input()
    
    if(len(set(x)) == 1):
        print(1, n-1, 2, n)
        
    else:
        a = x[:n//2]
        b = x[n//2 + 1:]
        
        if('0' in a):
            idx = a.index('0')
            print(idx+1, n, idx+2, n)
            
        elif('0' in x):
            idx = x.index('0')
            print(1, idx, 1, idx+1)