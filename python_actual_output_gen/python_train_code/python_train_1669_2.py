for _ in range(int(input())):
    n = int(input())
    a = sorted([int(i) for i in input().split()])
    
    if n == 1: print("T")
    else:
        summ = 0
    
        for i in range(n-2):
            summ += a[i]
            
        if a[n-1] >= summ: print("T")
        else:
            summ += a[n-1]
            
            if summ %2 == 0: print("HL")
            else: print("T")