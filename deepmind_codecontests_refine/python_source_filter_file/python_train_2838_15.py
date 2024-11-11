tests = int(input())
for test in range (tests) :
    x, y, z = sorted(map(int, input().split()))
    if y == z :
        print("YES")
        print(x, y, z)
    else :
        print("NO")
