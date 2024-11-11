l, r = map(int, input().split())
print("YES")
for i in range(1, r - l + 1, 2):
    print(i, i + 1)