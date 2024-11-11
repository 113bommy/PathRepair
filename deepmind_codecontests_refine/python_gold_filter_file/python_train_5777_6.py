n = int(input())
if n == 2 or n == 1:
    print(1)
    print(1)
    exit()
if n == 3:
    print(2); print(1, 3)
    exit()
print(n)
if n%2==0:
    if n == 4:
        print(3, 1, 4, 2)
        exit()
    g = n//2 + 1; foo = 1
    for i in range(g-1):
        print(foo, end=' ')
        print(g, end=' ')
        foo += 1; g += 1
else:
    print(1, end=' ')
    g = n//2 + 2
    foo = 2
    for i in range(n//2):
        print(g, end=' ')
        print(foo, end=' ')
        g += 1; foo += 1
        
