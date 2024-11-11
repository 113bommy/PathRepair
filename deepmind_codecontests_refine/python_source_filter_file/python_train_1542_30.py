n = int(input())
a = [0] + list(map(int, input().split()))

c = [0] * (n+1)
d = []

for i in reversed(range(1, n-1)):
    s = sum(c[::i])
    if s % 2 != a[i]:
        c[i] += 1
        d.append(str(i))

print(sum(c))
if sum(c) > 0:
    print(" ".join(d))