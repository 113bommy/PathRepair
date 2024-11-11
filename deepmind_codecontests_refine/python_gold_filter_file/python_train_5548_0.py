for _ in range(int(input())):
    n = int(input())
    arr = [list(input()) for i in range(n)]
    ar2 = [0, 0, 0]
    for i in range(n):
        for j in range(n):
            if arr[i][j] != "X":
                continue
            ar2[abs(i+j) % 3] += 1
    ii = ar2.index(min(ar2))
    #print(ii, "kek")
    for i in range(n):
        for j in range(n):
            if arr[i][j] != "X" or abs(i+j) % 3 != ii:
                continue
            #print("hello")
            arr[i][j] = "O"
    for r in arr:
        print("".join(r))
