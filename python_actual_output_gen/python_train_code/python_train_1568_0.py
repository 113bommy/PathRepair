t = int(input())
for _ in range(t):
    a, b = map(int, input().split())

    if b == a:
        print("YES")
        continue
    if b < a:
        print("NO")
        continue

    works = True
    aCount = 0
    bCount = 0
    i = 0
    c = 1 << i
    while c <= b:
        if b & c:
            bCount += 1
        if a % c:
            aCount += 1

        if bCount > aCount:
            works = False
            break

        i += 1
        c = 1 << i
    if not works:
        print("NO")
    else:
        print("YES")
