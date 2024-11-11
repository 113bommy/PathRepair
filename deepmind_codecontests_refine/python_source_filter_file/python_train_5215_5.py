n = input()
buf = 0
c = 0
m = 0

for i in range(len(n)):

    buf += int(n[i])
    m += 1
    if int(n[i]) % 3 == 0 or buf % 3 == 0 or m <= 3:
        buf = 0
        c += 1
        m = 0

print(c)
