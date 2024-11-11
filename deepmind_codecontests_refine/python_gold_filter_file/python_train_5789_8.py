L = [list(map(int, input().split())) for _ in range(4)]
for i in range(4):
    p = L[i][3]
    if p == 1:
        if i == 0:
            if L[0][0] == 1 or L[0][1] == 1 or L[0][2] == 1 or L[1][0] == 1 or L[2][1] == 1 or L[3][2] == 1:
                print("YES")
                exit()
        elif i == 1:
            if L[0][2] == 1 or L[1][0] == 1 or L[1][1] == 1 or L[1][2] == 1 or L[2][0] == 1 or L[3][1] == 1:
                print("YES")
                exit()
        elif i == 2:
            if L[0][1] == 1 or L[1][2] == 1 or L[2][0] == 1 or L[2][1] == 1 or L[2][2] == 1 or L[3][0] == 1:
                print("YES")
                exit()
        else:
            if L[0][0] == 1 or L[1][1] == 1 or L[2][2] == 1 or L[3][0] == 1 or L[3][1] == 1 or L[3][2] == 1:
                print("YES")
                exit()
print("NO")
