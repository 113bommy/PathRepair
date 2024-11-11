n = int(input())
a = [True] * (n+1)
r = []
for i in range(2, n+1):
    if a[i]:
        j = i
        while j <= n:
            a[j] = False
            j += j
        j = i
        while j <= n:
            r.append(j)
            j *= i
print(len(r))
print(*r)