from collections import Counter

h, w = map(int, input().split())
a = Counter(''.join(input() for _ in range(h)))

center = h * w % 2
side = (h // 2) * (w % 2) + (w // 2) * (h % 2)

cnt = 0
for i in a:
    if a[i] % 2 == 1:
        a[i] -= 1
        cnt += 1
if cnt != center:
    print('No')
    exit()

print('Yes' if sum(a[i] % 4==2 for i in a) == side else 'No')
