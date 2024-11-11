t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print(0)
        continue
    w = 0
    z = 1
    for x in range(1, n//2+1):
        w += 8*(x) * z
        z += 1
    print(w)