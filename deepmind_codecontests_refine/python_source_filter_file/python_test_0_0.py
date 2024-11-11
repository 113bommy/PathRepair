



n,m = list(map(int,input().split()))
arr = []
for i in range(n):
    arr.append([list(input()),i+1])
print(arr)
alps = list(map(chr, range(65, 91)))
d = {}
for a in range(len(alps)):
    d[alps[a]] = alps[len(alps)-1-a]
print(d)
print(arr[1][0][1])

for i in range(n):
    for j in range(m):
        if j%2:
            arr[i][0][j] = d[arr[i][0][j]]

arr.sort()
for i in range(n):
    print(arr[i][1],end = " ")









