n,m = map(int,input().split())
arr = []
for i in range(n):
    arr.append(input().split())
for i in range(n):
    for j in range(m):
        if arr[i][j] == '1' and (i == 0 or j == 0 or i == n-1 or j == m-1):
            print(2)
            quit()
print(4)
