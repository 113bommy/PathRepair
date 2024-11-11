n = int(input())
flag = True
for i in range(4):
    a, b, c, d = map(int, input().split())
    if a + c  <= n:
        print(i + 1, a, n - a)
        flag = False
        break
    elif a + d <= n:
        print(i + 1, a, n - a)
        flag = False
        break
    elif b + c <= n:
        print(i + 1, b, n - b)
        flag = False
        break
    elif b + d <= n:
        print(i + 1, b, n - b)
        flag = False
        break
if flag:
    print(-1)
