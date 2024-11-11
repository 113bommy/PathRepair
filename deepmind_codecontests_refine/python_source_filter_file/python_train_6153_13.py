n,d = map(int, input().split())
m = int(input())

def z(a,b,c,d,g,h):
    q=(c-a)*(h-b)-(d-b)*(g-a)
    return 0 if q < 0 else 1

for i in range(m):
    x,y = map(int, input().split())
    #print(z(2,0,n,n-d,x,y) + z(0,2,2,0,x,y) + z(n-d,n,0,2,x,y) + z(n,n-d,n-d,n,x,y))
    print("YES" if 3 < z(d,0,n,n-d,x,y) + z(0,d,d,0,x,y) + z(n-d,n,0,d,x,y) + z(n,n-d,n-d,n,x,y) or (x,y) == (n,n-d) or (x,y) == (n-d, n) or (x,y) == (0,2) or (x,y) == (2,0) else 'NO')