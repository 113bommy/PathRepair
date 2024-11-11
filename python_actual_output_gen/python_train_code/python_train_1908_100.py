n, m, k = map(int, input().split())

for i in range(n):
    for j in range(m):
        if k == i*(m-j) + j*(n-i):
            print("Yes")
            exit()

print("No")