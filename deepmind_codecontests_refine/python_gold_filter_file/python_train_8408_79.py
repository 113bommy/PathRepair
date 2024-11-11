n=int(input())
for i in range(-150,150):
    for j in range(-150,150):
        if(i**5-j**5==n):
            print(i,j)
            exit()
