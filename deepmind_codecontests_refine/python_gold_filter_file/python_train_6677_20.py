for i in range(int(input())):
    n, a, b = map(int, input().split())
    if(2*a > b):
        print((n//2)*b + (n%2)*a)
    else:
        print(n*a)