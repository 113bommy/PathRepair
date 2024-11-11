n, m = input(), sorted(map(int, input().split()))
t = 0
h = 0
for i in m:
    if i >= t:
        t += i
        h += 1
print(h)
