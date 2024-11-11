q = int(input())

for i in range(q):
    n, a, b = map(int, input().split())
    if 2*a <= b:
        print(n*a)
    else:
        print(n // 2 * b + a if n%2!=0 else 0)
