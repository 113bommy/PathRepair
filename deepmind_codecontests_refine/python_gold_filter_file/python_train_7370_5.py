import sys
input = sys.stdin.readline

n = int(input())
arr = sorted([list(map(int, input().rstrip().split())) for _ in range(n)])
cnt = {}
for i in range(n):
    for j in range(i + 1, n):
        dif = (arr[j][0] - arr[i][0], arr[j][1] - arr[i][1])
        cnt.setdefault(dif, 0)
        cnt[dif] += 1
print(1 if cnt == {} else n - max(cnt.values()))