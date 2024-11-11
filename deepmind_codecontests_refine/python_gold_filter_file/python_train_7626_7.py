

for _ in range(int(input())):
    
    p, f = map(int, input().split())
    
    cs, cw = map(int, input().split())
    
    s, w = map(int, input().split())
    
    if s > w:
        
        s, w = w, s
        
        cs, cw = cw, cs
        
    P = p // s
    
    F = f // s
    
    if P + F < cs:
        
        print(P + F)
        
    else:
        ans = cs
        for i in range(max(0, cs - F), min(P + 1, cs + 1)):
            
            ans = max(ans, cs + (p - s * i) // w + (f - s * (cs - i)) // w)
            
        print(min(ans, cs + cw))