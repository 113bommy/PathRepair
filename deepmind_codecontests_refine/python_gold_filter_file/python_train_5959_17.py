n,m,k = map(int, input().split())

print(n + m + n*m -3)

for i in range(n - 1):
    print("U" , end="")

for i in range(m - 1):
    print("L" , end="")

for i in range(n):
    if i & 1:
        for j in range(m - 1):
            print("L" , end="")
    else:
        for j in range(m - 1):
            print("R" , end="")
    if i < n - 1:
        print("D" , end="")

