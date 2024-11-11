tests = int(input())

for i in range(tests):
    k = int(input())
    i = 0
    x = 1
    while True:
        if x % 3 != 0 and x % 10 != 3:
            i += 1
        if i == k:
            break
        x += 1
    print(x)
