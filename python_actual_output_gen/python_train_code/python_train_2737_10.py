
n, k = map(int, input().split())
d = 240 - k
data = [5]

for i in range(1, n):
    data.append(data[i-1] + i * 5)

print(len(list(filter(lambda i: i <= d, data))))




