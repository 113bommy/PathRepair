s = str(input())
t = str(input())

if set(t).issubset(set(s)):
    p = -1
    r = 0
    
    for i in t:
        p = s.find(i, p+1)
        if p == -1:
            r += 1
            p = s.find(i)
        
    print(p + 1 + len(s)*r)
    
else:
    print(-1)