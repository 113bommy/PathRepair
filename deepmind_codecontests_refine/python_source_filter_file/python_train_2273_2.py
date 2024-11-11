N = int(input())
a = list(map(int, input().split()))

a.sort()

count = 0

while a:
    k = a.pop(0)
    k_count = 1
    while (len(a) > 0) and (a[0] == k):
        a.pop(0)
        k_count += 1
    if k_count < k:
        count += k_count
    else:
        count += k_count - k
print(count)
