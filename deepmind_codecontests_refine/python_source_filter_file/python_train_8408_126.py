
x = int(input())
for a in range(-500,500):
    for b in range(500):
        if a**5-b**5==x:
            print(a,b)
            exit()
