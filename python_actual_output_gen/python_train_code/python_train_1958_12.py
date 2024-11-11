t = int(input())



tk = []

for i in range (t):
    b,p,f = map(int, input().split())
    h,c = map(int, input().split())
    hp = 0
    hf = 0
    th = 0
    
    if h > c:
        for i in range (p):
            if b >= 2:
                b -= 2
                hp += h
        for i in range (f):
            if b >= 2:
                b -= 2
                hf += c
    elif c > h:
        for i in range (f):
            if b >= 2:
                b -= 2
                hf += c
        for i in range (p):
            if b >= 2:
                b -= 2
                hp += h
    th = hp + hf
    
    tk.append(th)
    
for i in tk:
    print(i)
    
            
        
                
            
            