x=int(input())

for i in range(1001):
    for j in range(-1001,1001):
        if i**5 - j**5==x:
            print(i,j)
            exit()
