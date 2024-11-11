w, m = map(int, input().split())
while m > 1:
    if m % w not in (0, 1, w - 1):
        print('NO'); exit()
    m = m // w + m % w == w - 1
print('YES')
