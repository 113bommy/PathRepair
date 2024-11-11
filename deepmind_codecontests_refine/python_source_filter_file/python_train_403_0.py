while True:
    n = int(input())
    if n == 0:
        break
    z = sorted([tuple(map(int, input().split())) for _ in range(n)],  key=lambda x: x[1])
    cnt = total = 0
    for a, b in z:
        total += a
        if total > b:
            cnt = 1
            break
    print("Yes" if cnt else "No")