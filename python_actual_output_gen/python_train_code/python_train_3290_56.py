n = int(input())

ans = False
for _ in range(n):
    name, bef, aft = input().split()
    bef = int(bef)
    aft = int(aft)
    if bef >= 2400 and bef > aft:
        ans = True

print("YES" if ans else "NO")