s = input().split(' ')
n = int(s[0])
k = int(s[1])
l = int(s[2])
c = int(s[3])
d = int(s[4])
p = int(s[5])
nl = int(s[6])
np = int(s[7])

x = k * l
q = c * d
t = p / np

count = 0

while x >= nl and q >= 1 and t >= 1:
    count += 1
    x -= nl
    q -= 1
    t -= 1

print(count // n)