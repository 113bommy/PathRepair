T = int(input())
for t in range(T):
    a = int(input())
    print("YES" if 360%(180-a) == 0 else "NO")