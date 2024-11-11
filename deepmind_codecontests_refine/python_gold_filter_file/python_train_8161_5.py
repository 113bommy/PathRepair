n, k = map(int, input().split())
for i in range(n):
    for j in range(n):
        print(k if i == j else 0, end = ' ')
    print()