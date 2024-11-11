n = int(input())
a = []
for i in range(n):
    a.append([int(x) for x in input().split()])
for j in range(n):
    for i in range(n):
        if a[j][i] == 1:
            continue
        ans = False
        for k in range(n):
            for m in range(n):
                if a[j][m] + a[i][k] == a[j][i]:
                    ans = True
        if ans == False:
            print("No")
            exit(0)
print("Yes")