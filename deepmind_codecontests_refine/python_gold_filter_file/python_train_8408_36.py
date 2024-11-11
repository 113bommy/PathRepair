X=int(input())
for i in range(-150,151):
    for j in range(-150,151):
        if i**5-j**5==X:
            print(i,j)
            exit()