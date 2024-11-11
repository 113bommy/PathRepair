x = int(input());a = (list(map(int, input().split())));b = max(a);n = sum(a)
while True:
    if n < (x * b)//2:
        print(b)
        exit()
    else:
        b += 1