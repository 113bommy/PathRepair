for t in range(int(input())):
    n = int(input())
    f = False
    for i in range(0, n//7+1):
        for j in range(0, n//5+1):
            for k in range(0, n//3 +1):
                if ((i*7) + (j*5) + (k*3) == n):
                    print(k,j,i)
                    f = True
                    break
            if f:
                break
        if f:
            break
    if f==False:
        print(-1)