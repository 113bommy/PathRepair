n = int(input())
q = []
for i in range(n):
    q.append([int(j) for j in input().split(' ')])
# print(q)
q.sort(key = lambda x: (-x[0], x[1]))
print(q)
res = 0
for i in range(n):
    a, b = q[i]
    res += a * i + b * (n-i-1)
print(res)