
t = int(input())

while(t):
    t -= 1
    
    n = int(input())
    x, y = [], []
    for i in range(n):
        a, b = map(int, input().split())
        x.append(a)
        y.append(b)
        
    x.sort()
    y.sort()
    
    if n % 2 == 1:
        print(1)
    else:
        s1 = x[n//2] - x[n//2]+1
        s2 = y[n//2] - y[n//2]+1
        
        print(s1*s2)