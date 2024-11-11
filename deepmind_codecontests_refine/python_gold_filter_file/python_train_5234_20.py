
x = 0
for i in range(int(input())):
    
    a, b = map(int, input().split())
    
    if (a % b) != 0:
        
        print(b - (a % b))
        
    else:
        print("0")