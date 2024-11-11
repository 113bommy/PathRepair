n = int(input())
a = n
for c in input():
    n += 1 if c == '+' else -1
    a = min(a, n)
print(a)