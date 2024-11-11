import math
c = int(input())
a = math.ceil(math.log10(c))
s = 0
for i in range(1, a):
    s = s + i*(9*10**(i-1))
s = s + (c - 10**(a-1)+1)*a
if c == 10**a:
    s = s + 2
print(s)