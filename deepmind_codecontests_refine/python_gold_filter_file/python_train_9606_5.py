import sys

t = int(input())

for _ in range(t):
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    ans = 0
    for j in range(29, -1, -1):
        cnt = 0
        for i in range(n):
            if (1 << j) <= arr[i] < (1 << (j + 1)):
                cnt += 1
        ans += cnt * (cnt - 1) // 2
    print(ans)
