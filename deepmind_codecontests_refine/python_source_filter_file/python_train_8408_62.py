x = int(input())

for i in range(20):
    for j in range(-20,20):
        if i**5 - j**5 == x:
            print(i,j)
            exit()
