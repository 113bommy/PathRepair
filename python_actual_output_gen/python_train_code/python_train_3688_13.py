n = int(input())
for _ in range(n):
    x, n = map(int, input().split())
    arr = list(map(int, input().split()))

    even = 0
    odd = 0

    for q in arr:
        if q % 2 != 0:
            odd += 1
        else:
            even += 1

    if odd % 2 != 1:
        odd -= 1

    if odd < 0:
        print('No')
        continue

    if x < odd and even == 0:
        if x % 2 == 0:
            print('No')
        else:
            print('Yes')
        continue

    if x > odd + even:
        print('No')
    else:
        print('Yes')

