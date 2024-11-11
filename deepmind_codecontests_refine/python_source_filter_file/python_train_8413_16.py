from math import sqrt

q = int(input())

p = []
for _ in range(q):
    p.append(list(map(int, input().split())))

for t in p:
    x = min(t)
    y = max(t)
    if x == y or x + 1 == y:
        print(x * 2 - 2)
    else:
        temp = sqrt(x * y)
        hoge = int(temp)
        if hoge == temp:
            hoge -= 1
        if hoge * (hoge + 1) > x * y:
            print(2 * hoge - 2)
        else:
            print(2 * hoge - 1)

