N = int(input())

S = [3*5*7, 3*5*11, 3*5*13, 3**3*5]

ans = 0
for s in S:
    if s <= N:
        ans += 1
print(ans)