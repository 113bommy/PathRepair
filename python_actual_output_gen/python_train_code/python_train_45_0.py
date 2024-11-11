def kamni(x,y):
    ky = y//2
    kx = x
    q = min(ky,kx)
    return q


t = int(input())
for i in range(t):
    a,b,c = map(int,input().split())

    r = kamni(b,c) 
    b = b - r
    
    l = kamni(a,b)
    print(int(l + r * 3))