s = input().split()
l = int(s[0])
r = int(s[1])
x = -1
for i in range(l, r):
    s = str(i)
    if s.count('0') <= 1 and s.count('1') <= 1 and s.count('2') <= 1 and s.count('3') <= 1 and s.count(
            '4') <= 1 and s.count('5') <= 1 and s.count('6') <= 1 and s.count('7') <= 1 and s.count(
        '8') <= 1 and s.count(
        '9') <= 1:
        x = i
        break

print(x)
