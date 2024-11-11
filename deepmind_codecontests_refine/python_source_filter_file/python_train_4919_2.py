n, s = map(int, input().split())

flag = False

B = [2] * (n - 1) + [s - 2 * (n - 1)]
if s > 2 * (n - 1):
    print("YES")
    print(*B)
    print(1)
else:
    print("NO")