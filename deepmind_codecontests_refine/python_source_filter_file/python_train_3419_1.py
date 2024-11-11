h, w, d = map(int, input().split())

cols = [[0]*w for i in range(h)]
if d % 2 == 1:
    for i in range(h):
        for j in range(w):
            cols[i][j] = "RY"[(i+j)%2]
else:
    arr = [[0]*(4*d) for i in range(4*d)]
    for i in range(d):
        for j in range(d):
            arr[i+d][j] = arr[i][j+d] = 2
    for i in range(d):
        for j in range(d):
            if abs(i) + abs(j) <= d//2-2:
                arr[i][j] = arr[i+d][j+d] = 1
                arr[i+d][j] = arr[i][j+d] = 3
            if abs(d-1-j) + abs(d-1-i) <= d//2-1:
                arr[i][j] = arr[i+d][j+d] = 1
                arr[i+d][j] = arr[i][j+d] = 3
            if abs(d-1-j) + abs(i) <= d//2-2:
                arr[i][j] = arr[i+d][j+d] = 3
                arr[i+d][j] = arr[i][j+d] = 1
            if abs(j) + abs(d-1-i) <= d//2-1:
                arr[i][j] = arr[i+d][j+d] = 3
                arr[i+d][j] = arr[i][j+d] = 1
    for i in range(h):
        for j in range(w):
            cols[i][j] = "RGBY"[int(arr[i%(4*d)][j%(4*d)])]
print("\n".join("".join(e) for e in cols))

