(n, k) = list(map(int, input().split()))
d = list(map(int, input().split()))

acc = 0
for dd in d:
    print((dd + acc) //k, end='')
    acc = (dd + acc) % k