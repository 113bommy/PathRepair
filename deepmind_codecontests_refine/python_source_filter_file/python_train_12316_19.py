"""
    Created by Жама on 27.03.2016.
"""
a = []
for i in range(4):
    a.append(int(input()))

n = int(input())
b = [0] * n
for i in range(4):
    for j in range(a[i], n, a[i]):
        b[j] = 1

print(sum(b))
