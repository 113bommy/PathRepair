t = int(input())
for _ in range(t):
    n = int(input())
    if n == 2:
        print(1)
        print(2)
    else: 
        print(n)
        print(*[i for i in range(1, n+1)])