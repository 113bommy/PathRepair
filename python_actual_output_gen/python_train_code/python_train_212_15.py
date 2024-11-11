a, b, c = map(int, input().split())
for d1 in range(101):
    for d2 in range(101):
        if a * d1 + b * d2 == c:
            print('Yes')
            exit(0)
print('No')
