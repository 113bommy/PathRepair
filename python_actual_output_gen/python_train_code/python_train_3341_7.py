n, d = map(int, input().split())
arr = list(map(int, input().split()))
rez = 2
for i in range(n - 1):
    rez += max(0, arr[i + 1] - arr[i] - d * 2 + 1)
print(rez)
