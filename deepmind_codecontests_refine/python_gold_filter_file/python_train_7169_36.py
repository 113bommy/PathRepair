for _ in range(int(input())):
    a,b,c,d,e,f,g,h=map(float, input().split())
    
    if abs((c-a)*(h-f) - (g-e)*(d-b)) < 1e-10:
        print("YES")
    else:
        print("NO")