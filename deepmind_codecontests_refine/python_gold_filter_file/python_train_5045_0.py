n = int(input())
listd = []
res = 0

for i in range(n):
    listd.append(tuple(map(int, input().split())))
listd.sort()

for a, b in listd:
    res = b if res<=b else a

print(res)
