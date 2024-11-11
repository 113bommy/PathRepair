t = int(input())

for _ in range(t):
    n0, n1, n2 = list(map(int, input().split()))
    if(n2 > 0):
        s = '11'
        n2 -= 1
    elif(n1 > 0):
        s = '10'
        n1 -= 1
    else:
        s = '00'
        n0 -= 1
    while(n0 > 0 or n1 > 0 or n2 > 0):
        if(n2 > 0):
            s += '1'
            n2 -= 1
        elif(s[-1] == '0' and n0 > 0):
            s += '0'
            n0 -= 1
        elif(s[-1] == '1' and n1 > 0):
            s += '0'
            n1 -= 1
        elif(s[-1] == '0' and n1 > 0):
            s += '1'
            n1 -= 1
            
        
    print(s)

    
