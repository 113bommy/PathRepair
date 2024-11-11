n, t = map(int, input().split())

flag = False
for i in range(int("1" + "0" * (n - 1)), int("9" * n)):
    if not i % t:
        flag = True
        print(i)
        break

if not flag:
    print(-1)