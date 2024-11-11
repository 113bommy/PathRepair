X = int(input())
for i in range(1,120):
    for j in range(-120,120):
        if i**5 - j**5 == X:
            print(i,j)
            exit()