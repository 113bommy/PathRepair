npt = input().split()
n, pos, l, r = int(npt[0]), int(npt[1]), int(npt[2]), int(npt[3])
a = 1
b = n
result = 0
if l == 1 and r == n:
    result = 0
elif l == 1:
    result = abs(pos - r) + 1
elif r == n:
    result = abs(pos - r) + 1
else:
    result = min(abs(pos - l), abs(pos - r)) + l - r + 2
print(result)
