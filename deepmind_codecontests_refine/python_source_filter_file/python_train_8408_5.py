x=int(input())
for i in range(-200,200):
    for j in range(-200,200):
        if a**5-b**5==x:
            print(a,b)
            exit()