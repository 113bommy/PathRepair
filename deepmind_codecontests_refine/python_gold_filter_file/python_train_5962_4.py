from math import gcd
for _ in range(int (input())):
    m , d, w = map (int , input().split())
    x = gcd(d-1,w)
    x= w//x;
    m = min(m,d);
    dem = m//x
    print(dem*m - x * dem*(dem+1)//2 )
#1000000000 888888889 444444444
