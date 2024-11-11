h,w = map(int,input().split())
alp = "qwertyuiopasdfghjklzxcvbnm"
c = [0]*26
for i in range(h):
    s = input()
    for i in range(26):
        c[i] += s.count(alp[i])
for i in range(26):
    c[i] %= 4
c2 = c.count(2)
c2 += c.count(3)
for i in range(26):
    c[i] %= 2
c1 = c.count(1)
a2 = 0
a1 = 0
if h%2 == 1:
    a2 += w//2
if w%2 == 1:
    a2 += h
if h%2 == 1 and w%2 == 1:
    a1 = 1
if c2 <= a2 and c1 <= a1:
    print("Yes")
else:
    print("No")