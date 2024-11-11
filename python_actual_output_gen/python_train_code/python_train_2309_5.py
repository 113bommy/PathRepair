q = int(input())
for _ in range(q):
    n, a, b = [*map(int, input().split())]
    if (a <= b//2):
        print(a*n)
    else:
        print(n*b//2 if b%2 == 0 else (n-1)*b//2 + a)