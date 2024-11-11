from math import log,log2
def func(a):
    if a == 1:
        return -1
    
    div2 = a & (-a)
    div3  = a // div2
    pow2 = round(log2(div2))
    
    
    pow3 = round(log(div3, 3))
   
    if 3 ** pow3 != div3:
        return -1
    
    if pow2 > pow3:    
        return -1
    
    if pow2 == pow3:
        return pow2
    
    return pow2 + ((pow3 - pow2) * 2)

t = int(input())
for _ in range(t):
    a = int(input())
    print(func(a))