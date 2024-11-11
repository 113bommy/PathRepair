a = input()
s = [a.count('B'), a.count('S'), a.count('C')]
b = list(map(int, input().split()))
c = list(map(int, input().split()))
d = int(input())
l = 0
r = d + max(s) + 1
while (r - l) > 1:
    v = (r + l) // 2
    if max(0, v * s[0] - b[0]) * c[0] + max(0, v * s[1] - b[1]) * c[1] + max(0, v * s[2] - b[2]) * c[2] <= d:
        l = v
    else:
        r = v
print(l)