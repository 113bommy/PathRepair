n, k = (int(x) for x in input().split())
for i in range(n):
    for j in range(n):
        if i == j:
            print(k, end='')
        else:
            print(0, end='')
    print()
