X=int(input())
while True:
    for x in range(2,X):
        if X%x==0:
            break
    else:
        print(x)
        break
    X+=1