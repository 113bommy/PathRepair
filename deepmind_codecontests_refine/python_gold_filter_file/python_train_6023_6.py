h,w = map(int,input().split())

ans = 10**10

if h * w % 3 == 0:
    print(0)
    exit()

ans = min(ans,w,h)

for i in range(1,h//2+1):
    a = [w * i, (h - i) * (w // 2), (h - i) * (w // 2 + w % 2)]
    a.sort()
    ans = min(ans, a[2] - a[0])
for i in range(1, w//2+1):
    a = [h * i, (w - i) * (h // 2), (w - i) * (h // 2 + h % 2)]
    a.sort()
    ans = min(ans, a[2] - a[0])
print(ans)