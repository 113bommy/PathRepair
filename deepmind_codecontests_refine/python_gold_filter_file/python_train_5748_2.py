a = int(input())
b = list(map(int, input().split()))
for i in range(a):
    b[i] = (b[i], -i)
b.sort()
k = int(input())
for q in range(k):
    a = list(map(int, input().split()))
    l = a[0]
    p = a[1]
    print(sorted(b[-l:], key = lambda x: -x[1])[p - 1][0])