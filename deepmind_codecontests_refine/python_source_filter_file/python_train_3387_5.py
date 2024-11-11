s = input().split()
n, k = int(s[0]), int(s[1])
s = input().split()
a = []
for x in s:
    a.append(int(x))
L, R = [], []
for i in range(n + 2):
    L.append(0)
    R.append(0)
for i in range(1, n + 1):
    if a[i - 1] == 1:
        L[i] = L[i - 1] + 1
for i in range(n, 0, -1):
    if a[i - 1] == 1:
        R[i] = R[i + 1] + 1
zeros = []
for i in range(n + 2):
    zeros.append(0)
c = 0
for i in range(1, n + 1):
    c += (a[i - 1] == 0)
    zeros[i] = c
z = 0
l, r = 0, k + 1
left, right = -1, -1
while l <= r and r <= n:
    t = zeros[r - 1] - zeros[l]
    if t > k:
        l += 1
    else:
        x = L[l] + R[r] + (r - l - 1)
        if x > z:
            z = x
            left, right = l + 1, r - 1
        r += 1
print(z)
for i in range(n):
    if i + 1 >= left and i + 1 <= right:
        print("1", end=" ")
    else:
        print(a[i], end=" ")