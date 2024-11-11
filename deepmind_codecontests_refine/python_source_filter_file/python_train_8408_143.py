x=int(input())

for i in range(101):
    for j in range(-101,101):
        if i**5 - j**5==x:
            print(i,j)
            exit()
