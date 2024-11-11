n, m = map(int, input().split())
arr = []
for i in range(n):
    arr.append(list(str(input().strip())))
 
for i in range(len(arr)):
    lastAssign = "W" if i % 2 == 0 else "B"
    for j in range(len(arr[0])):
        if arr[i][j] == ".":
            arr[i][j] = lastAssign
        lastAssign = "B" if lastAssign == "W" else "W"
 
for y in arr:
    print("".join(i for i in y))