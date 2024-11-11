

for _ in range(int(input())):
    a, b = map(int, input().split())
    k = min(a, b) * 2
    if k >= max(a, b):
        print(pow(k, 2))
    else:
        print(pow(b, 2))
