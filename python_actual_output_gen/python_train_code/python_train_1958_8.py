t = int(input())

for i in range(t):
    
    b, p, f = list(map(int, input().split()))
    h, c = list(map(int, input().split()))

    total = 0
    num_g = min(b//2, p)
    num_c = min(b//2, f)

    if h > c or (h==c and num_g > num_c):
        num_g = min(b//2, p)
        total += num_g * h
        b -= num_g * 2

        num_c = min(f, b // 2)
        total += num_c * c
        print(total)
    elif c > h:
        num_c = min(f, b // 2)
        total += num_c * c
        b -= num_c * 2

        num_g = min(b//2, p)
        total += num_g * h
        print(total)
