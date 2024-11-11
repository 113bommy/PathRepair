x = int(input())

for a in range(1, 120):
    for b in range(-119, 119):
        if a**5-b**5 == x:
            print(a, b)
            exit()