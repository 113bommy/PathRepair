n = int(input())
while(n):
    sum = 0
    a,b = map(int,input().split())
    if a == 1:
        print(b^2)
    elif a>b:
        print(b)
    else:
        z = (b//a) +1
        x = z-1
        m = b%a
        r = a - m
        sum += (m * (z^2))
        sum += (r * (x^2))
        print(sum)
    
    n-=1
