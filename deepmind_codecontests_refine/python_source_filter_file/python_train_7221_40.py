for i in range(5):
    mat = list(map(int,input().split()))
    for j in range(5):
        if mat[j] == 1:
            print("\n" + str(abs(i - 3) + abs(j - 3)))
            break
