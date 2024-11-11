n = int(input())

for a in range(500):
    for b in range(-500,500):
        if a**5-b**5==n:
            print(a,b)
            exit()

