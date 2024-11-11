t = int(input())
for _ in range(t):
    a = int(input())
    print("YES" if 360 % (180-a) == 0 else "NO")