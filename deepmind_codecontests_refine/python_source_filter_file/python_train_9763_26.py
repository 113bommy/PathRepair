a, b, c, k = map(int, input().split())
if a >= k:
    print(a)
else:
    print(a - ((k-a)-b)