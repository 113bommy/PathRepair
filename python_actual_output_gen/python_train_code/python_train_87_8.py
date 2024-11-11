num = int(input())
for _ in range(num):
    n = int(input())
    n2 = n
    count = 0
    while n != 1:
        if n % 6 != 0:
            count += 1
            n *= 2
            if n > 1000000000 or n <= 0:
                print(count)
                break
        else:
            n = int(n/6)
            count += 1
    else:
        print(count)