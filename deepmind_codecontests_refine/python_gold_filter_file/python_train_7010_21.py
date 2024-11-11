a, b = map(int, input().split(' '))

if a == 0 and b == 0:
    print(0, 0)
    quit()
    
if a <= b:
    if a == 0:
        print("Impossible")
    else:
        print(b, (a-1) + b)
        
else:
    if b == 0:
        print(a, a)
        quit()
    print(a, (a-1) + b)
