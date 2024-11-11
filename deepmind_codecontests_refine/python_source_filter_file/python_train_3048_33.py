def yeeter():
    n=int(input())
    x=[]
    y=[]
    for i in range(n):
        ye=input().split()
        x.append(int(ye[0]))
        y.append(int(ye[1]))

    for i in range(n):
        print(x[i]^y[i])
