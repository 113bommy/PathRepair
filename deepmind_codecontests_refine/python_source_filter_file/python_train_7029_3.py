from sys import stdin
n = int(input())
if n == 1:
    print(6)
    exit()
arr = stdin.read().strip().splitlines()
ans = 6
for i in range(n):
    for j in range(i + 1, n):
        s = 0
        for k in [0, 1, 2, 3, 4, 5]:
            if arr[i][k] == arr[j][k]:
                s += 1
        if s < 2:
            ans = min(ans, 1)
        elif s < 4:
            ans = 1
        elif s < 6:
            print(0)
            exit()
print(ans)