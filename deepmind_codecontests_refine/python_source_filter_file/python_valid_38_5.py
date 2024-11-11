t = int(input())
for i in range(t):
    time = 0
    n = int(input())
    if n <= 6:
        time = 15
    else:
        if n % 2 != 0:
            n += 1
        time = (n * 5)/2
    print(time)