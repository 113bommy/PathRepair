a = [[[0] * 10 for i in range(3)] for j in range(4)]

n = int(input())

for _ in range(n):
    [b, f, r, v] = [int(j) - 1 for j in input().split()]
    a[b][f][r] = v + 1

for i, d in enumerate(a):
    for c in d: print("", *c)
    if i != len(a) - 1:
        print("#" * 20)
