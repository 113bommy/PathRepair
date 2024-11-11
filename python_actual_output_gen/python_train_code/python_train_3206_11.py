n = int(input())
a = list(map(int, input().split()))
start = [1] * n
for i in range(n - 2, -1, -1):
    if a[i] < a[i + 1]:
        start[i] += start[i + 1]
end = [1] * n
for i in range(1, n):
    if a[i] > a[i - 1]:
        end[i] += end[i - 1]
ret = max(start)
for i in range(n):
    if i + 1 < n:
        ret = max(ret, start[i + 1] + 1)
    if i - 1 >= 0:
        ret = max(ret, end[i - 1] + 1)
    if i + 1 < n and a[i + 1] - a[i - 1] > 1:
        ret = max(ret, end[i - 1] + 1 + start[i + 1])
print(ret)