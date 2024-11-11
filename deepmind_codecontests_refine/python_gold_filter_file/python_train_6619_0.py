n = int(input())
a = list(map(int, input().split()))
now = set()
an = 0
for i in range(2 * n):
    t = a[i]
    if t in now:
        now.remove(t)
    else:
        now.add(t)
        an = max(an, len(now))
print(an)
