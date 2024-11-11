t = int(input())
for _ in range(t):
    x, y = list(map(int, input().split()))
    c1, c2, c3, c4, c5, c6 = list(map(int, input().split()))
    a1 = min(c1, c6 + c2)
    a2 = min(c2, c1 + c3)
    a3 = min(c3, c2 + c4)
    a4 = min(c4, c3 + c5)
    a5 = min(c5, c4 + c6)
    a6 = min(c6, c5 + c1)
    if x > 0 and y > 0:
        if x > y:
            ans = a1 * y + a6 * (x - y)
        else:
            ans = a1 * x + a2 * (y - x)
    elif x > 0 and y < 0:
        ans = a5 * (-y) + a6 * x
    elif x < 0 and y > 0:
        ans = a2 * y + a3 * (-x)
    else:
        x *= -1; y *= -1
        if x > y:
            ans = a4 * y + a3 * (x - y)
        else:
            ans = a4 * x + a5 * (y - x)
    print(ans)
        
            
    
            
