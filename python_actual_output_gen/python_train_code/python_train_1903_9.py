k, n = map(int, input().split())
a = list(map(int, input().split()))
kankaku = [(a[i] - a[i-1]) % 20 for i in range(len(a))]
print(k-max(kankaku))