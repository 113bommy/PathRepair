s = input()

piv = s.index('^')
l = 0
r = 0
k = 1
for i in range(piv - 1, -1, -1):
    if s[i] != '=':
        w = int(s[i])
        l += k * w
        k += 1

k = 1
for i in range(piv + 1, len(s)):
    if s[i] != '=':
        w = int(s[i])
        r += k * w
        k += 1

if l == r:
    print("balance")
elif l < r:
    print("right")
else:
    print("left")