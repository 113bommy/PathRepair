n, s = list(map(int, input().split()))
x = s // n
if x > 0:
    x = 1
print(s // n + x)