T=int(input())
def res(A,B):
    j = 0
    x = 0
  
    # While either A or B is non-zero 
    while (A or B): 
          
        # Position at which both A and B 
        # have a set bit 
        if ((A & 1) and (B & 1)): 
              
            # Inserting a set bit in x 
            x += (1 << j) 
  
        # Left shifting both numbers to 
        # traverse all the bits 
        A >>= 1
        B >>= 1
        j += 1
    return x 
  
for i in range(T):
    (a,b)=tuple(map(int,input().split()))
    x=res(a,b)
    v=a^x+b^x
    print(v)