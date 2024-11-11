r = int(input())
n = list()
k = list()
count = 0
for i in range(r):
    a, b = map(int, input().split())
    n.append(a)
    k.append(b)
print(n)
for x in range(r):
    while count < n[x]:
        for j in range(k[x]):
            print(chr(j+97), end='')
            count += 1
            if count == n[x]:
                break
    count = 0
    print()