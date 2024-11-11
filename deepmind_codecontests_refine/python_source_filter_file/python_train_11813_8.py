def getColumn(i):
    Temp = []
    for j in range(X[0]):
        Temp.append(S[j][i])
    return Temp


def setColumn(i):
    for j in range(X[0]):
        Answer[j][i] = 0


def setRow(i):
    for j in range(X[1]):
        Answer[i][j] = 0


def ShowMat():
    for i in range(X[0]):
        print(*Answer[i])
    print()


X = list(map(int, input().split()))
Zeros, Ones = [], []
S = [list(map(int, input().split())) for i in range(X[0])]
Answer = [[1] * X[1] for i in range(X[0])]
for i in range(X[0]):
    for j in range(X[1]):
        if S[i][j] == 0:
            Zeros.append([i, j])
        else:
            Ones.append([i, j])
for i in Zeros:
    setRow(i[0])
    setColumn(i[1])
for i in Ones:
    if 1 not in Answer[i[0]]+getColumn(i[1]):
        print("NO")
        exit()
print("YES")
ShowMat()
# Let's see who is the best !!!
# ravenS_The_Best
