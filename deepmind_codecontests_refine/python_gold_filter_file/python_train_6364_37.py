n = int(input())
arr = [int(x) for x in input().split()]
t = []
for i in range(101):
    s = 0
    for j in arr:
        s += max(0, abs(j - i) - 1)
    t.append(s)
p = t[1:].index(min(t)) + 1
print(p, min(t))