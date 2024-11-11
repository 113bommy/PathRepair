N, P = [int(_) for _ in input().split()]

mp = {}
for i in range(2, int(P**0.5) + 1):
    while P % i == 0:
        mp[i] = mp.get(i, 0) + 1
        P //= i
mp[P] = mp.get(P, 0) + 1
ans = 1
for i in mp.keys():
    ans *= max(i * (mp[i] // N), 1)
print(ans)

