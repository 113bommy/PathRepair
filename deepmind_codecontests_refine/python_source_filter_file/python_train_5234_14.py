x = 0
for i in range(int(input())):
    
    a, b = map(int, input().split())
    
    if (b % a) != 0:
        
        print(b - (b % a))
        
    else:
        print("0")