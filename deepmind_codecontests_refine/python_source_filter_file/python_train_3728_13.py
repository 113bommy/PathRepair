x, y, z, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split())))
ab, abc = [], []

for i in a:
    for j in b:
        ab.append(i+j)

ab.sort()
s = ab[x*y-k:]
for i in s:
    for j in c:
        abc.append(i+j)

abc.sort(reverse=True)
for i in range(k):
    print(abc[i])