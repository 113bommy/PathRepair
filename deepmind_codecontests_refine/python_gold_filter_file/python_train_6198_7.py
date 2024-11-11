ans = 0.0
n = int(input())
m = list(map(int, input().split()))
r = list(map(int, input().split()))
d = list(0 for i in range(50000))
for i in range(len(m)):
    num = m[i]
    for j in range(num - r[i], 50001, num):
        d[j-1] = 1
print(round(sum(d)/50000, 10))