x=int(input())
for i in range(-500,501):
    for j in range(-500,501):
        if i**5-j**5==x:
            print(i,j)
            exit()