for test in range(int(input())):
    n = int(input())
    x,y,z = -1,-1,-1
    for i in range((n // 3) + 1):
        for j in range((n // 5) + 1):
            k = n - 3 * i - 5 * j 
            if k >= 0:
                if k % 7 == 0:
                    x,y,z = i,j,k // 7
    if x != -1 :
        print(x,y,z)
    else :
        print(-1)
