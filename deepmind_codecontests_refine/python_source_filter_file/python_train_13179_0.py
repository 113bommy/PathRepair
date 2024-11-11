import sys


n = int(input())
a = [0] * n
for i in range(n):
    a[i] = list(map(int, input().split()))

for x in range(n):
    for y in range(n):
        if a[x][y] != 1:
            for t in range(n):
                if (a[x][y] - a[t][y]) in a[x]:
                    break
            else:
                print("No")
                sys.exit()
print("True")
