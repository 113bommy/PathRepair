from collections import Counter
a, b, c, s = input(), input(), Counter(), 0
k = len(b) - len(a) + 1
c[0] = b.count('0', 0, k)
for i in range(1, len(a)):
    c[i] = (b[i + k - 1] == '0') - (b[i] == '0') + c[i - 1]
for i in range(len(a)):
    s += [c[i], k - c[i]][a[i] == '0']
print(s)