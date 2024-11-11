a, b, n = map(int, input().split())
res = None
for i in range(1, 10):
    if int(str(a)+str(i)) % b == 0:
        res = str(a)+str(i)
        break
if res is None:
    print(-1)
else:
    print(res+('0'*(n-1)))
