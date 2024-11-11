n, v = [int(x) for x in input().split()]
a = list(map(int, input().split()))
b = list(map(int, input().split()))
rate = v
for i in range(n):
    s = float(b[i]/a[i])
    rate = min(rate, s)
su = sum(a)
num = max(su * rate, v)
print('%.1f'%(num))


