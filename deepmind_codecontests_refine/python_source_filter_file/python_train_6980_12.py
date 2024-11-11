n = int(input())
apartment = [[[0 for r in range(10)] for f in range(3)] for b in range(4)]
for _ in range(n):
    b, f, r, v = map(int, input().split())
    apartment[b-1][f-1][r-1] += v
for b in range(4):
    if(b != 0):
        print('#' * 20)
    for f in range(3):
        print(' '.join(map(str, apartment[b][f])))
