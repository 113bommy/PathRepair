n = int(input())
s = input()
s0 = ''
c = 0
for i in range(10):
    if c > n - 1:
        break
    s0 += s[c]
    c += i
print(s0)