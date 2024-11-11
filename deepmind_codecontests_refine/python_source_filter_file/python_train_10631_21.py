n = int(input())
v = list(map(int, input().split()))
rest = n-1
print(n+1)
for i in range(n-1, -1, -1):
    add = n - (v[i]%n) + rest
    print("2 " + str(i+1) + " " + str(add))
    for j in range(i+1):
        v[j] += add
    rest -= 1
print("1 " + str(n) + " " + str(n))