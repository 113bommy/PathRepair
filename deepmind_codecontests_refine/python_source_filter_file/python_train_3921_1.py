n, p = map(int, input().split())
v = [int(i) for i in input().split()]
v2 = [v[0]]
for i in range(0, n-1):
    v2.append(v2[i]+v[i+1])

max = 0
for i in range(n):
    if (v2[i]%p) + ((v2[n-1]-v2[i])%p) > max:
        max = (v2[i]%p) + ((v2[n-1]-v2[i])%p)
        print((v2[i]%p) + ((v2[n-1]-v2[i])%p))
# print(max)
# print(v2)
