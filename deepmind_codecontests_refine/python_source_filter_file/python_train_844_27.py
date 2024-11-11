import sys
from collections import Counter

def fmax(m):
    s ='abcd'
    if m <= 4:
        return s[:m] 
    if m>4:
        c =''
        for i in range(m//4):
            c = c+s
        r = m%4
        if r== 0:
            return s
        if r!=0:
            return s+s[:r]
            

    
    
            
if __name__ == '__main__':    
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    m = data[0]
    
        
    print(fmax(m))
    