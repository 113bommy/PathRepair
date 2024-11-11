a, b = [int(i) for i in input().split()]
d = [6, 2, 5, 5, 4, 5, 6, 3, 8, 6]
s = 0
for i in range(a, b + 1):
    s += sum([d[int(j)] for j in str(i)])
print(s)
