m, n, c = input().split()
m = int(m)
n = int(n)
a = [[j for j in input()]for i in range(m)]
inxs = list()
con = list()
fin = list()
for i in range(m):
    for j in range(n):
        if a[i][j] == c:
            inxs.append(i)
            inxs.append(j)
            # if i == 0:
            #     if j == 0:
            #         if (a[0][1] != '.') & (a[0][1] != c):
            #             con += 1
            #         if (a[1][0] != '.') & (a[1][0] != c):
            #             con += 1
            #     if j == n-1:
            #         if (a[0][n-2] != '.') & (a[0][n-2] != c):
            #             con += 1
            #         if (a[1][n-1] != '.') & (a[1][n-1] != c):
            #             con += 1
            # if i == m-1:
            #     if j == 0:
            #         if (a[m-1][1] != '.') & (a[m-1][1] != c):
            #             con += 1
            #         if (a[m-2][0] != '.') & (a[m-2][0] != c):
            #             con += 1
            #     if j == n-1:
            #         if (a[m-1][n-2] != '.') & (a[m-1][n-2] != c):
            #             con += 1
            #         if (a[m-2][n-1] != '.') & (a[m-2][n-1] != c):
            #             con += 1
for i in range(0, len(inxs), 2):
    if inxs[i+1] > 0:
        if (a[inxs[i]][inxs[i+1]-1] != c) & (a[inxs[i]][inxs[i+1]-1] != '.'):
            con.append(a[inxs[i]][inxs[i+1]-1])
    if inxs[i+1] < n-1:
        if (a[inxs[i]][inxs[i+1]+1] != c) & (a[inxs[i]][inxs[i+1]+1] != '.'):
            con.append(a[inxs[i]][inxs[i+1]+1])
    if inxs[i] > 0:
        if (a[inxs[i]-1][inxs[i+1]] != c) & (a[inxs[i]-1][inxs[i+1]] != '.'):
            con.append(a[inxs[i]-1][inxs[i+1]])
    if inxs[i] < m-1:
        if (a[inxs[i]+1][inxs[i+1]] != c) & (a[inxs[i]+1][inxs[i+1]] != '.'):
            con.append(a[inxs[i]+1][inxs[i+1]])
for i in con:
    if i not in fin:
        fin.append(i)
print(len(fin))
# def index_2d(a, c):
#     for i, e in enumerate(a):
#         try:
#             return i, e.index(c)
#         except ValueError:
#             pass
#     raise ValueError("{} is not in list".format(repr(c)))
# print(index_2d(a, c))
