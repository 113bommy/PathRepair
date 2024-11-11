__author__ = '-'

l1 = input().strip().split(" ")
m = int(l1[0])
n = int(l1[1])

B = []
for i in range(m):
    line = input().strip().split(" ")
    row = []
    for p in line:
        row.append(int(p))
    B.append(row)

A = [[0 for x in range(n)] for y in range(m)]

def transferA(B,m,n):
    A = [[0 for x in range(n)] for y in range(m)]

    for i in range(m):
        rida1 = True
        for j in range(n):
            if B[i][j] == 0:
                rida1 = False
                break
        if rida1:
            for j in range(n):
                veerg1 = True
                for r in range(m):
                    if B[r][j] == 0:
                        veerg1 = False
                        break
                if veerg1 and rida1:
                    A[i][j] = 1
    return A

A = transferA(B,m,n)
def transfer(A,m,n):
    C = [[0 for x in range(n)] for y in range(m)]
    for i in range(len(A)):
        for j in range(len(A[i])):
            if A[i][j] == 1:
                for k in range(n):
                    C[i][k] = 1
                for l in range(m):
                    C[l][j] = 1
    return C


C = transfer(A,m,n)

if C == B:
    print("YES")
    for i in range(len(C)):
        for j in range(len(C[i])):
            print(C[i][j],end = " ")
        print()
else:
    print("NO")
