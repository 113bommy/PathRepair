n = int(input())
lst = list(map(int, input().split()))
lst.sort()
w = [0] * 100005
for i in lst:
    w[i] += 1
res = [0] * 100005
res[1] = w[1]
for i in range(2, 100005):
    res[i] = max(res[i - 1], res[i - 2] + w[i] * i)
print(res[n])