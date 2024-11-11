n, k = map(int, input().split())
a = list(map(int, input().split()))
a = [i - 1 for i in a]
g = [-1] * n

i = 0
j = 0
while g[j] == -1:
    if i == k:
        print(j + 1)
        exit()
    g[j] = i
    i += 1
    j = a[j]

for i in range((k - g[j]) % (i - g[j])):
    j = a[j]
print(j + 1)