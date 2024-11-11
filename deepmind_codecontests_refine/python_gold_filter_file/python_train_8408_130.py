n=int(input())
for i in range(-200,200):
    for j in range(-200,200):
        if(i**5-j**5==n):
            print(i,j)
            exit()
