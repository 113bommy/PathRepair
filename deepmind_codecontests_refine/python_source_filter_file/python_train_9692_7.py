n, m = map(int, input().split())
a = []
for i in range(m):
    b = input()
    a.append(b)
    if 'B' in b:
        l = b.find('B')
        r = b.rfind('B')
        d = (l + r) // 2
        print(1 + i + (r - l) // 2, d + 1)
        break
