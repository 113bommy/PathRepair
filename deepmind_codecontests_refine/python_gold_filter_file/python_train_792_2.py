m, n = map(int, input().split())
arr = [] 


for i in range(m):
    arr.append(input())

check = [[0] * n for i in range(m)]
# check columns

for i in range(n):
    for j in range(m):
        cnt = 0
        for k in range(j +1, m):
            if (arr[j][i] == arr[k][i]):
                cnt += 1
                check[k][i] = 1
        if (cnt > 0):
            check[j][i] = 1
#print(check)
#check rows

for i in range(m):
    for j in range(n):
        cnt = 0
        for k in range(j + 1, n):
            if (arr[i][j] == arr[i][k]):
                cnt += 1
                check[i][k] = 1
        if (cnt > 0) :
            check[i][j] = 1
#print(check)
res = ""
for i in range(m):
    for j in range(n):
        if check[i][j] == 0:
            res = res + arr[i][j]
print(res) 
