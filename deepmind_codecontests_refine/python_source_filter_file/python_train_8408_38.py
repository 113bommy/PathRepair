x = int(input())
for a in range(120):
    for b in range(-1, a):
        if a**5 - b**5 == x:
            print(a, b)
            exit()
