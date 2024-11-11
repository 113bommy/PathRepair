def to2th(a):
    ans = ''
    while (a != 0):
        if (a %2 == 0):
            ans += '0'
        else:
            ans += '1'
        a = a//2
    return ans[::-1]

def hw(x):
    ps = 0
    for i in range(0, len(x)):
        if (x[-1-i] == '0'):
            ps = i + 1
    return ps

a, b = map(int, input().split())
a = to2th(a)
b = to2th(b + 1)
if len(a) == len(b):
    print(hw(a) - hw(b))
else:
    ans = hw(a)
    for i in range(len(a) + 1, len(b)):
        ans += i - 1
    ans += len(b) - 1 - hw(b)
    print(ans)