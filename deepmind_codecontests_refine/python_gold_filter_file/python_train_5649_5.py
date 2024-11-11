t = int(input())
while t > 0:
    t -= 1
    a = input()
    res = len(a)
    mn = 0
    bal = 0
    for i in range(len(a)):
        if a[i] == '+': 
            bal += 1
        else:
            bal -= 1
        if bal < mn:
            mn = bal
            res += i + 1
    print(res)
        
        
    
                
