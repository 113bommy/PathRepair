x=int(input())
for a in range(-200,201,1):
    for b in range(-200,200,1):
        if a**5-b**5==x:
            print(a,b)
            exit()
