def compute(S, X): 
    A = (S - X)//2
    a = 0
    b = 0
  
    # Traverse through all bits 
    for i in range(64): 
        Xi = (X & (1 << i)) 
        Ai = (A & (1 << i)) 
        if (Xi == 0 and Ai == 0): 
            # Let us leave bits as 0. 
            pass
              
        elif (Xi == 0 and Ai > 0): 
            a = ((1 << i) | a)  
            b = ((1 << i) | b)  
          
        elif (Xi > 0 and Ai == 0): 
            a = ((1 << i) | a)  
            # We leave i-th bit of b as 0. 
  
        else: # (Xi == 1 and Ai == 1) 
            #print("Not Possible") 
            return
  
    return a,b
t=int(input())
for _ in range(t):
    n=int(input())
    l=list(map(int,input().split()))
    Sum=sum(l)
    xr=0
    for x in l:
        xr=xr^x
    
    #Sum,xr=map(int,input().split())
    a,b=compute(2**63-Sum-xr,(2**63)//2)
    #print(a,b,a+b,a+b+xr)
    l.append(xr)
    l.append(a)
    l.append(b)
    xr=0
    for x in l:
        xr=xr^x
    print(3)
    print(*l[-3:])
