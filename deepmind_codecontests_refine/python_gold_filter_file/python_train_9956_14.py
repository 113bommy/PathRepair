a, b, c = map(int, input().split())
a %= b;
cnt = 1
v = [False for i in range(0, 1000000 + 2)]
while True:
    a *= 10
    num = a // b
    if (v[a]):
        print(-1)
        exit(0)
    v[a] = True
    if (num == c):
        print(cnt);
        exit(0)
    a %= b
    cnt += 1
