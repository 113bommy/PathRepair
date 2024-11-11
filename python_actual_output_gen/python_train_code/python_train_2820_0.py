n = int(input())
a = list(map(int, input().split(' ')))
q = int(input())
for i in range(q):
    b, e = list(map(int, input().split(' ')))
    a[b:e] = a[e-1:b-1:-1]

print(' '.join(list(map(str, a))))
