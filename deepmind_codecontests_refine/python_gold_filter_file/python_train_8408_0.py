x=int(input())
for a in range(999):
    for b in range(-a, a):
        if a**5 - b**5 == x:
            print(a, b)
            exit()