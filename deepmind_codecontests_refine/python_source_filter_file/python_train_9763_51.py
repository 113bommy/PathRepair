a, b, c, k = map(int, input().split())
if k <= a+b:
    print(min(a, k)
else:
    print(2*a+b-k)