def h1(k) :
 
    if k % 4 == 0 :
        return k
 
    if k % 4 == 1 :
        return 1
 
    if k % 4 == 2 :
        return k + 1
 
    return 0
for _ in range(int(input())):
    x, y = map(int, input().split())
    
    sum = h1(x-1)
    if sum == y: 
        print(x)
    elif sum ^ y == x: 
        print(x+2)
    else: print(x+1)