n = int(input())
ans = 7 + 3*(n-1)

print(ans)
print(0, 1)
print(0, 2)

for i in range(1, n+1):
    for j in range(3):
        print(i, j)

print(n+1, 0)
print(n+1, 1)