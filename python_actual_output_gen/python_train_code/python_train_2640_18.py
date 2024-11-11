n = int(input())
s = [int(i) for i in input().split()]
p = [0] * (n+1)
for i in range(n):
    p[i+1] = p[i] + s[i]
last = p[-1]//2
L, R = 1, n+1
while R - L > 1:
    m = (R+L)//2
    if p[m] > last:
        R = m
    else:
        L = m
last = L
while last > 0:
    now = p[last]
    proper_rest = p[-1] - now
    L, R = 0, n+1
    while R - L > 1:
        m = (R+L)//2
        if p[m] > proper_rest:
            R = m
        else:
            L = m
    if p[L] == proper_rest:
        break
    last -= 1
print(p[last])