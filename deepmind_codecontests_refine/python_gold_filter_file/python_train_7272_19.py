n = int(input())
t = list(map(int, input().split()))
a = list(map(int, input().split()))
mod = 10 ** 9 + 7

tmax, amax = max(t), max(a)
if not any(ti == ai == tmax == amax for ti, ai in zip(t, a)):
    print(0)
    exit()

ans = 1
for i in range(1, n - 1):
    if ((t[i - 1] < t[i] and t[i] > a[i])
        or (a[i] > a[i + 1] and t[i] < a[i])):
            print(0)
            break
    elif t[i - 1] == t[i] and a[i] == a[i + 1]:
        ans = ans * min(t[i], a[i]) % mod
else:
    print(ans)
