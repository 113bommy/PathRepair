n = input()
s = tuple(map(int, input().split()))
m = 1e9 + 1
t = 0
for i in s:
    t += i
    if i % 2 and i < m:
        m = i
print(0 if m > 1e9 else t - m if t % 2 else t)
