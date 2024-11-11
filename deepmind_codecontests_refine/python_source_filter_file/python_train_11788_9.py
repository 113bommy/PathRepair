for _ in range(int(input())):
    #n = int(input())
    l  = list(input())
    for i in range(len(l)):
        l[i] = int(l[i])
    
    prev = -1
    d = 0
    o = 0
    for i in l:
        if i==1:
            if prev!=1:
                prev = 1
            else:
                prev = -1
                o+=d
                d=0        
        else:
            if(prev==1):
                d+=1
    print(o)
            
    
