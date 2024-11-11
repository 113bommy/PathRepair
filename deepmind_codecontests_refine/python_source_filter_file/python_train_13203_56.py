n = int(input())
flag = True
for _ in range(N):
    t, x, y = map(int, input().split())
    if (t < x + y) or (x + y + t) % 2==1:
        flag = False


if flag:
    print("Yes")
else:
    print("No")
