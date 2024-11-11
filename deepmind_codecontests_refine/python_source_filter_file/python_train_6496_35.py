n, m = map (int, input().split())
print(n)
print(m)
l = list(map (int, input().split()))
k1 = 1
count = 0

for k2 in l:
    print(k1, k2, count)
    if k1 < k2:
        count = count + (k2 - k1)
        k1 = k2
    elif k1 > k2:
        count = count + (n - k1 + k2)
        k1 = k2
    elif k1 == k2:
        pass

print(count)