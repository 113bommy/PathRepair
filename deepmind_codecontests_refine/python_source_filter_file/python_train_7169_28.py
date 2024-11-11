for _ in range(int(input())):
    a,b,c,d,e,f,g,h=map(float, input().split())
    
    if abs((c-a)*(h-f) - (d-b)*(g-e)) < 1e-10:
        print("Yes")
    else:
        print("No")