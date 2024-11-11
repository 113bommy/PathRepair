Q = int(input())

while Q:
    Q -= 1
    A, B = map(int, input().split())
    M = max(A, B)
    m = min(A, B)
    if M == m:
        print(2 * m - 2)
        continue
    if M == m + 1:
        print(2 * m - 2)
        continue
    last = int((M * m) ** 0.5)
    if last == (M * m) ** 0.5:
        last -= 1
    if last * (last + 1) >= M * m:
        print(last * 2 - 2)
    else:
        print(last * 2 - 1)
