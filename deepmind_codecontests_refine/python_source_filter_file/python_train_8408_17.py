X=int(input())
for i in range(-1500,1501):
    for j in range(-1500,1501):
        if (i**5)-(j**5)==X:
            print(i,j)
            exit()
