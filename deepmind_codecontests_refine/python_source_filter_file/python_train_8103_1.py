D = int(input())

def table(i, k):
    if i == k:
        return list(range(9, -1, -1)) + [0]*9
    else:
        return list(range(10, 0, -1)) + list(range(1, 10))

def nine(i):
    return 10**i - 1

def rec(d, i, k):
    res = 0
    num  = table(i, k)
    if i == 1:
        for j in range(-9, 10):
            if 9*j == d:
                return num[j]
        return 0
    if i == 2:
        for j in range(-9, 10):
            if d == 99*j:
                return 10*num[j]
    if not -10*nine(i) <= d <= 10*nine(i):
        return 0
    for j in range(-9, 10):
        if d%10 == j*nine(i)%10:
            res += num[j] * rec((d-j*nine(i))//10, i-2, k)
    return res

l = 0
while D % 10 == 0:
    D//= 10
    l += 1

if l == 0:
    a = 1
else:
    a = 9*10**(l-1)

ans = 0
for i in range(1, 13):
    if not l:
        ans += rec(D, i, i)
    else:
        ans += rec(D, i, 100)
print(a * ans)