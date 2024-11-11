n, k = map(int, input().split())
mod = set()
b = True
for i in range(1, k):
    if n % k in mod:
        b = False
        break
    else:
        mod.add(n%k)
if b:
    print('Yes')
else:
    print('No')