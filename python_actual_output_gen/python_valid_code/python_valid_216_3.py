n = int(input())
*a, = map(int, input().split())
b = sorted(a)
for i in a:
    print(a[(b.index(i) + 1) % n], end=' ')