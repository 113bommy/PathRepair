while 1:
    n = input()
    if n == 0:
        break
    
    sum_a = 0
    sum_b = 0
    
    for i in range(n):
        a,b = map(int, input().split())
        
        if a > b:
            sum_a = sum_a + a + b
        elif a < b:
            sum_b = sum_b + a + b
        elif a == b:
            sum_a = sum_a + a
            sum_b = sum_b + b

    print("%s %s" %(sum_a,sum_b))

        

