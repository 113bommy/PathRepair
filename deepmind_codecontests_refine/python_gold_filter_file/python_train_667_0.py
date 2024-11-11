s = input().split()
s1 = input().split()
s2 = input().split()
n = int(s[0])
V = int(s[1])
a = []
b = []
num = 0
while num < n :
    a.append(int(s1[num]))
    num += 1
num = 0
while num < n :
    b.append(int(s2[num]))
    num += 1
x = float(b[0] / a[0])
ans = float(0)
num = 1
while num < n :
    x = min(x, b[num] / a[num])
    num += 1
num = 0
while num < n :
    ans = ans + a[num] * x
    num += 1
print('%.4f' %min(ans, V))