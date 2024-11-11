n = int(input())
t = list(map(int, input().split()))
s = sum(t)
if s & 1: print(0)
else:
    k = s // 2
    for i in range(n - 1):
        t[i + 1] += t[i]
    print(t.count(k))