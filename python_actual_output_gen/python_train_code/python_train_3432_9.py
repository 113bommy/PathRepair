a, b, c = map(int, input().split())
a %= b;
cnt = 1
v = [False for i in range(0, 100000 + 2)]
while True:
    a *= 10
    num = a // b
    if (v[num]):
        print(-1)
        exit(0)
    v[num] = True
    if (num == c):
        print(cnt);
        exit(0)
    a %= b
    cnt += 1
