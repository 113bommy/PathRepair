x = int(input())

for a in range(100):
    for b in range(-100,100,1):
        if a**5-b**5 == x:
            print(a,b)
            exit()