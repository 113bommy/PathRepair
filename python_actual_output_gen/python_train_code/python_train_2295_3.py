n, k, x = map(int, input().split())
a = list(map(int, input().split()))

for i in range(k):
    a[i-1-i] = x

print(sum(a))
