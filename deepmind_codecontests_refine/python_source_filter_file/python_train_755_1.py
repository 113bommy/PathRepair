def answer(x) :
    x = [int(y) for y in x]
    M = max(x)
    
    for i,tup in enumerate(zip(x[:-1],x[1:])) :
        a,b = tup
        
        if a == M and b < M :
            return i
        
        if a < M and b == M :
            return i + 1
    
    return -1
        
        
t = int(input()) 
for _ in range(t) :
    input()
    x = input()
    print(answer(x.split(" ")))