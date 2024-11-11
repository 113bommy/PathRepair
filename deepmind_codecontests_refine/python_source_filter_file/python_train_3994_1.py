n, k = map(int, input().split())
a = list(map(int, input().split()))
a.insert(0,0)
count = 0
j = 0
c = [0]*int(1e5 + 5)
for i in range(1, n + 1):
    c[a[i]] += 1

    if c[a[i]] == 1:
        count += 1

    while count == k:
        j += 1
        c[a[j]] -= 1

        if c[a[j]] == 0:
            print(j, i)
            exit()
print("-1, -1")