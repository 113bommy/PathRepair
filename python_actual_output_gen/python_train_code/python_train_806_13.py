*s, d = (map(int, input().split()))
s = sorted(s)
print(s, d)
move = 0
if abs(s[0]-s[1]) < d:
    move += d- abs(s[0]- s[1])
if abs(s[1]-s[2])< d:
    move += d - abs(s[1]-s[2])
# print((d-(abs(s[1]-s[0])))+(d-(abs(s[1]-s[2]))))
print(move)