A, B, C, D, E, F = map(int, input().split())
water = [(A * i + B * j) * 100 for i in range(11) for j in range(11)][1:]
sugar = [C * i + D * j for i in range(101) for j in range(101)]

ans = [100, 0]
for w in water:
    for s in sugar:
        if w + s <= F and s <= E * w // 100:
            if s / (w + s) > ans[1] / ans[0]:
                ans = [w + s, s]
            
print(*ans)