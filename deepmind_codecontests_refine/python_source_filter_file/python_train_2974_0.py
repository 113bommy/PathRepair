n = int(input())
s = input()
i = n
t = "o" + ("go" * i)
while i > 0:
    while s.count(t) >= 1:
        x = s.find(t)
        l = len(t)
        s = s[0:x] + ("*" * l) + s[x+l::]
    i -= 1
    t = "o" + ("go" * i)
print(s)