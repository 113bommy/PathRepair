T = int(input())
for t in range(T):
    a = int(input())
    print("Yes" if 360%(180-a) == 0 else "No")