n = int(input())
a = list(map(int, input().split(' ')))
q = int(input())
for i in range(q):
    b, e = list(map(int, input().split(' ')))
    a[b:e] = a[b:e][::-1]

print(' '.join(list(map(str, a))))
