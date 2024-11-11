a = list(map(int, input().split()))
n = len(a)
k = [i for i in a]
lst = []
for i in range(n):
    p = k[i]%n
    ans = 0
    a = k[i+1:] + k[:i+1]
    k[-1] = 0
    for j in range(n):
        if (a[j] + 1 + int(k[i]//n))%2 == 0 and j < p:
            ans += a[j] + 1 + int(k[i]//n)
        elif (a[j] + int(k[i]//n))%2 == 0 and j >= p:
            ans += a[j] + int(k[i]//n)
    lst.append(ans)

print(max(lst))
