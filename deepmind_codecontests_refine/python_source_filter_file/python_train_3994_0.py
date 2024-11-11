n, k = map(int, input().split())
a = list(map(int, input().split()))

a.insert(0, 0)

# Create Dictionary
c = {}
count = 0
j = 0

for i in range(1, n + 1):
    if a[i] in c:
        c[a[i]] += 1
    else:
        c[a[i]] = 1
    if c[a[i]] == 1:
        count += 1
    while count == k:
        j += 1
        if a[j] not in c:
            c[a[j]] = 0
        c[a[j]] -= 1
        if c[a[j]] == 0:
            print(j, i)
            exit()

print("-1, -1")
