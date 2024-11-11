n = int(input())
l = list(map(int, input().split()))
r = list(map(int, input().split()))

k = []
for i in range(n):
    k.append(n - l[i] - r[i])

err = False
for i in range(n):
    lk = rk = 0
    for j in range(i):
        if k[j] > k[i]:
            lk += 1
    for j in range(i+1, n):
        if k[j] > k[i]:
            rk += 1

    if l[i] != lk or r[i] != rk:
        err = True
        break

if err:
    print("NO")
else:
    print("YES")
print(" ".join(map(str, k)))