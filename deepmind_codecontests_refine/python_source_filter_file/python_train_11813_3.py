m,n = list(map(int, input().split()))
b = []
a = []
new_b = []
for _ in range(m):
    b.append(list(map(int, input().split())))
    a.append([1]*n)
    new_b.append([0]*n)

for i, row in enumerate(b):
    for j, col in enumerate(row):
        if col == 0:
            for c in range(n):
                a[i][c] = 0
            for r in range(m):
                a[r][j] = 0
print(a)
for i, row in enumerate(b):
    for j, col in enumerate(row):
        flag = 0
        for c in range(n):
            if a[i][c] ==1:
                flag = 1
                break
        if flag==0:
            for r in range(m):
                if a[r][j] ==1:
                    flag = 1
                    break
        new_b[i][j] = flag
if new_b == b:
    print("YES")
    for row in a:
        for item in row:
            print(item,  end=" ")
        print()
else:
    print("NO")
        

    