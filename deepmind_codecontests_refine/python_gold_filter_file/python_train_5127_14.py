p = int(input())
for i in range(p):
    result = 0
    n, k = map(int, input().split())
    if n % 2 == 0:
        result = n + 2
        result += (k-1) * 2
    else:
        c = 3
        while n % c != 0:
            c += 1
        result = c + n + (k-1) * 2
    print(result)
