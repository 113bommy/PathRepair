x=int(input())
for i in range(-80,80):
    for j in range(-80,80):
        if i**5-j**5==x:
            print(i,j)
            exit()