x = int(input())

for i in range(300):
    for j in range(-300,300):
        if i ** 5 - j** 5 == x:
            print(i,j)
            exit()