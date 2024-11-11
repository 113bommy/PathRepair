n, k = map(int, input().split())
v = list(map(int, input().split()))
lim = min(n, k)
ans = [0]

for a in range(lim+1):
    for b in range(lim-a+1):
        hand = sorted(v[:a]+v[n-b:])
        hs = sum(hand)
        for i in range(min(lim-a-b, a+b)):
            test = hand[i]
            if test < 0:
                hs -= test
        ans.append(hs)

print(max(ans))