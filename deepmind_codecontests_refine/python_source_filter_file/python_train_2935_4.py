n=int(input())
for i in range(n):
    for j in range(n):
        if((i+j)%2==0):
            print("w",end="")
        else:
            print("b",end="")
    print("")