def chocolate(n, a):
    row = [0] * n
    col = [0] * n
    for i in range(0, n):
        for j in range(0, n):
            if a[i][j] == "C":
                row[i] += 1
                col[j] += 1
    #print(row)
    #print(col)
    total = 0
    for each in row:
        total += (each * (each - 1) / 2)
    for each in col:
        total += (each * (each - 1) / 2)
    print(total)
#INPUT
n = int(input())
a = []
for i in range(0, n):
    tmp = input()
    a.append(tmp)
chocolate(n, a)

"""
3
.CC
C..
C.C
ans=4
"""