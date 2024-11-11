import math
n = int(input())
l = [0] * 26
for i in range(n):
    a = input()
    l[ord(a[0]) - 97] += 1
print(l)

f = math.factorial
sum = 0
for i in l:
    if i > 2:
        a = i//2
        b = i - a
        if a > 1:
            sum += f(a) / f(a - 2) / f(2)
        sum += f(b) / f(b - 2) / f(2)
print(int(sum))