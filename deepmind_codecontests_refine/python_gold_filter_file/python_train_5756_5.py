y = int(input())
for _ in range(y):
    n = int(input())
    print(2)
    a = n
    b = n-1
    for i in range(n-1):
        print(a,b)
        a = (a+b+1)//2
        b -= 1