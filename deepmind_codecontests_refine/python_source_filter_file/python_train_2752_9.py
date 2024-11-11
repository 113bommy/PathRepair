from sys import stdin
_ = stdin.readline()
s = stdin.readline()[:-1].split(' ')
print(s)
n = 0
p = 0
for i in s:
    if i == "-1":
        if p > 0: p -= 1
        else: n += 1
    else:
        p += int(i) if int(i) <= 10 else 10
print(n)
