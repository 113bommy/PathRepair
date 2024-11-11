n = int(input())
data = []
ans = 0
for i in range(n):
    data.append(list(map(int, input().split())))
    ans += data[i][1]
data.sort(key=lambda x: x[0] - x[1])
k = -1
if sum([abs(data[i][1] - data[i][0]) for i in range(n)]):
    for i in range(n):
        if data[i][0] > data[i][1]:
            k = max(k, data[i][1])
    print(ans-k)
else:
    print(0)