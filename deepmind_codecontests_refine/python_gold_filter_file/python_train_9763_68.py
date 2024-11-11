a, b, c, k = map(int, input().split())
if k <= a+b:
    print(min(k, a))
else:
    print(2*a-k+b)
