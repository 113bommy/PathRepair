for i in range(int(input())):
    x = list(map(int,input()))
    z = len(x) * (len(x) +1)//2
    print((x[0]-1)*z)
