t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    if n % 2 == 0:
        print(n*(m//2))
    elif n % 2 != 0:
        print((n*((m-1)//2)) + ((n+1)//2))