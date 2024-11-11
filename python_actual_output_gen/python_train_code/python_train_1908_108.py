n, m, k = map(int, input().split())

for i in range(1, n+1):
    for j in range(1, m+1):
        if k == n*j + m*i - 2*i*j:
            print("Yes")
            exit()
print("No")