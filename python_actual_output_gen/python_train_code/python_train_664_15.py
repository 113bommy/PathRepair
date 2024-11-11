n = int(input())
for test in list(map(int, input().split())):
    if test < 15:
        print("NO")
        continue
    test %= 14
    print("YES" if test < 7 else "NO")
