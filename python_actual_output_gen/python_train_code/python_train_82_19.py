t = int(input())

for i in range(t):
    n = int(input())
    a = 1000000001
    b = 0
    for j in range(n):
        l, r = map(int, input().split())
        if l>=b:
            b = l
        if r<=a:
            a = r
    if n == 1:
        print(0)
    else:
        print(b-a)
        
