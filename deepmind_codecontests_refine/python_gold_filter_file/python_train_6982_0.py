bfr = [[[0 for _ in range(10)] for _ in range(3)] for _ in range(4)]

n = int(input())
for _ in range(n):
    b, f, r, v = map(int, input().split())
    bfr[b-1][f-1][r-1] += v
for b in range(4):
    for f in range(3):
        print(' ' + ' '.join(map(str, bfr[b][f])))
    if b != 3:
        print('#'*20)
