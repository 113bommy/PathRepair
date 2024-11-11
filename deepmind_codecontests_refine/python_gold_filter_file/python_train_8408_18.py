X=int(input())
for i in range(-200,201):
    for j in range(-200,201):
        if (i**5)-(j**5)==X:
            print(i,j)
            exit()