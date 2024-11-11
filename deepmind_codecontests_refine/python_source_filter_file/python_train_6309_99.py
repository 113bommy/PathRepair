n, k = [int(x) for x in input().split()]

if int(n / k) % 2 != 0:
    print("YES")
else:
    print("NO")