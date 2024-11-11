test_cases = int(input())
 
for t in range(test_cases):
    
    c, d = input().split()
    
    c = int(c)
    d = int(d)
    
    if (c+d)%2==0 and c+d>=0:
        if c==0 and d==0:
            print("0")
        elif c==d:
            print("1")
        else:
            print("2")
    else:
        print("-1")