a, b = map(int, input().split())
s = float('inf')
for i in range(a):
    c, d = map(int, input().split())
    if c / d < s:
        s = c / d
print(s)
