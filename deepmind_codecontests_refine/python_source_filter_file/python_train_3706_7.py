import sys

n, m = map(int, input().split())
for i in range(n + 1, m + 1):
    count = 0
    for j in range(2, i):
        if j % i == 1:
            count += 1
    if count == 0:
        if i == m:
            print("YES")
            sys.exit(0)
        print("NO")
        sys.exit(0)
print("NO")
