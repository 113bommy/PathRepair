t = int(input())
for _ in range(t):
    n,m = map(int, input().split())
    S = []
    for i in range(n):
        s = list(str(input()))
        s = [int(i) for i in s]
        S.append(s)
    ans = []
    for i in range(n-1):
        for j in range(m-1):
            if i == n-2 and j == m-2:
                X0 = []
                X1 = []
                if S[i][j] == 0:
                    X0.append((i+1, j+1))
                else:
                    X1.append((i+1, j+1))
                if S[i+1][j] == 0:
                    X0.append((i+2, j+1))
                else:
                    X1.append((i+2, j+1))
                if S[i][j+1] == 0:
                    X0.append((i+1, j+2))
                else:
                    X1.append((i+1, j+2))
                if S[i+1][j+1] == 0:
                    X0.append((i+2, j+2))
                else:
                    X1.append((i+2, j+2))
                #print(X0)
                #print(X1)
                if len(X1) == 1:
                    temp = list(X0[0])+list(X0[1])+list(X1[0])
                    ans.append(temp)
                    temp = list(X0[0])+list(X0[2])+list(X1[0])
                    ans.append(temp)
                    temp = list(X0[1])+list(X0[2])+list(X1[0])
                    ans.append(temp)
                elif len(X1) == 2:
                    temp = list(X0[0])+list(X0[1])+list(X1[0])
                    ans.append(temp)
                    temp = list(X0[0])+list(X0[1])+list(X1[1])
                    ans.append(temp)
                elif len(X1) == 3:
                    temp = list(X1[0])+list(X1[1])+list(X1[2])
                    ans.append(temp)
                elif len(X1) == 4:
                    temp = list(X1[1])+list(X1[2])+list(X1[3])
                    ans.append(temp)
                    temp = list(X1[0])+list(X1[1])+list(X1[2])
                    ans.append(temp)
                    temp = list(X1[0])+list(X1[1])+list(X1[3])
                    ans.append(temp)
                    temp = list(X1[0])+list(X1[2])+list(X1[3])
                    ans.append(temp)
                else:
                    pass
                S[i][j] = 0
                S[i+1][j] = 0
                S[i][j+1] = 0
                S[i+1][j+1] = 0
            elif i == n-2:
                if S[i][j] == 1 and S[i+1][j] == 1:
                    temp = [i+1, j+1, i+2, j+1, i+1, j+2]
                    ans.append(temp)
                    S[i][j] = 1-S[i][j]
                    S[i+1][j] = 1-S[i+1][j]
                    S[i][j+1] = 1-S[i][j+1]
                elif S[i][j] == 1:
                    temp = [i+1, j+1, i+1, j+2, i+2, j+2]
                    ans.append(temp)
                    S[i][j] = 1-S[i][j]
                    S[i][j+1] = 1-S[i][j+1]
                    S[i+1][j+1] = 1-S[i+1][j+1]
                elif S[i+1][j] == 1:
                    temp = [i+2, j+1, i+1, j+2, i+2, j+2]
                    ans.append(temp)
                    S[i+1][j] = 1-S[i+1][j]
                    S[i][j+1] = 1-S[i][j+1]
                    S[i+1][j+1] = 1-S[i+1][j+1]
                else:
                    pass
            elif j == m-2:
                if S[i][j] == 1 and S[i][j+1] == 1:
                    temp = [i+1, j+1, i+1, j+2, i+2, j+2]
                    ans.append(temp)
                    S[i][j] = 1-S[i][j]
                    S[i][j+1] = 1-S[i][j+1]
                    S[i+1][j+1] = 1-S[i+1][j+1]
                elif S[i][j] == 1:
                    temp = [i+1, j+1, i+2, j+2, i+2, j+2]
                    ans.append(temp)
                    S[i][j] = 1-S[i][j]
                    S[i+1][j] = 1-S[i+1][j]
                    S[i+1][j+1] = 1-S[i+1][j+1]
                elif S[i][j+1] == 1:
                    temp = [i+1, j+2, i+2, j+2, i+2, j+2]
                    ans.append(temp)
                    S[i][j+1] = 1-S[i][j+1]
                    S[i+1][j] = 1-S[i+1][j]
                    S[i+1][j+1] = 1-S[i+1][j+1]
                else:
                    pass
            else:
                if S[i][j] == 0:
                    continue
                else:
                    temp = [i+1, j+1, i+1, j+2, i+2, j+1]
                    ans.append(temp)
                    S[i][j] = 1-S[i][j]
                    S[i][j+1] = 1-S[i][j+1]
                    S[i+1][j] = 1-S[i+1][j]
    print(len(ans))
    for i in range(len(ans)):
        print(*ans[i])
