q = int(input())
for i in range(q):
    l, r, L, R = map(int, input().split())
    if l != R:
        print(l, R)
    else:
        print(r, L)
