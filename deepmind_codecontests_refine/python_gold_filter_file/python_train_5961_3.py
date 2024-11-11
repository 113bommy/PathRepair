n = int(input())
ans = 7 + 3*(n-1)

print(ans)
print(0, 0)
print(0, 1)

for i in range(1, n+1):
    for j in range(3):
        print(i, i-1+j)

print(n+1, n)
print(n+1, n+1)